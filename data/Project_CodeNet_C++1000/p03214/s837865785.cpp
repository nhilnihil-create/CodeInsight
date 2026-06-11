#include <bits/stdc++.h>
using namespace std;

int main(){
  double N;
  cin >> N;
  vector<double> a(N);
  for(int i=0;i<N;i++)  cin >> a.at(i);

  double ave=0;
  for(int i=0;i<N;i++)  ave+=a.at(i);
  ave/=N;
  double mi=1e9;
  for(int i=0;i<N;i++)  mi=min(mi,abs(ave-a.at(i)));
  for(int i=0;i<N;i++){
    if(abs(ave-a.at(i))==mi){
      cout << i << endl;
      return 0;
    }
  }

  return 0;
}