#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,t; cin>>n>>t;
  bool flag = 0;
  int ans=1000;
  for(int i=0; i<n; i++){
    int c,time; cin>>c>>time;
    if(time<=t){
      flag = 1;
      ans = min(ans,c);
    }
  }
  if(flag) cout << ans << endl;
  else cout << "TLE" << endl;
}