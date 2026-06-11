#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,t;
  cin >> n >> t;
  bool ok=false;
  int ans=1000,a,b;
  for(int i=0;i<n;i++){
    cin >> a >> b;
    if(b<=t){
      ans=min(ans,a);
      ok=true;
    }
  }
  if(ok)
    cout << ans << endl;
  else
    cout << "TLE" << endl;
  return 0;
}