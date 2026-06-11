#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,t;
  cin >> n >> t;
  int ans=100000000;
  bool ok=false;
  for(int i=0;i<n;++i){
    int cost,time;
    cin >> cost >> time;
    if(time<=t){
      ans=min(ans,cost);
      ok=true;
    }
  }
  if(ok){
    cout << ans << endl;
  }else{
    cout << "TLE" << endl;
  }
  return 0;
}
