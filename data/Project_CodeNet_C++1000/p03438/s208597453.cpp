#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int64_t> a(N),b(N);
  int64_t sump=0;
  int64_t sumn=0;
  for(int i=0;i<N;i++){
    cin >> a.at(i);
  }
  for(int i=0;i<N;i++){
    cin >> b.at(i);
  }
  for(int i=0;i<N;i++){
    if(b.at(i)-a.at(i)>0){
      sump+=(b.at(i)-a.at(i))/2;
    }else if(b.at(i)-a.at(i)<0){
      sumn-=(b.at(i)-a.at(i));
    }
  }
  if(sump>=sumn){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  return 0;
}
