#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,g;
  cin >> n >> g;
  int su=0,mini=10e5,baf;
  for(int i=0;i<n;i++){
    cin >> baf;
    su+=baf;
    mini=min(mini,baf);
  }
  int ans=n;
  ans+=(g-su)/mini;
  cout << ans << endl;
  return 0;
}