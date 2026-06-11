#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<long long> a(N);
  for(int i=0;i<N;i++)  cin >> a.at(i);
  vector<long long> b(N);
  for(int i=0;i<N;i++)  cin >> b.at(i);

  long long cntB=0;
  for(int i=0;i<N;i++){
    if(a.at(i)<b.at(i)){
      long long tmp=(b.at(i)-a.at(i)+1)/2;
      cntB+=tmp;
      a.at(i)+=tmp*2;
    }
  }
  for(int i=0;i<N;i++){
    cntB-=a.at(i)-b.at(i);
  }

  if(cntB>=0)  cout << "Yes" << endl;
  else  cout << "No" << endl;

  return 0;
}