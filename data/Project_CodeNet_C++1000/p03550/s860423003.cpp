#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,Z,W;
  cin >>N>>Z>>W;
  vector<int>a(N);
  for(int i=0;i<N;i++){
    cin>>a.at(i);
  }
  if(N==1){
    cout<<abs(a.at(0)-W)<<endl;
  }else{
    int kotae=max(abs(a.at(N-1)-W),abs(a.at(N-2)-a.at(N-1)));
    cout<<kotae<<endl;
  }
  return 0;
}