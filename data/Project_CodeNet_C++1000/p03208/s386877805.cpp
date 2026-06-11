#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,k;
  cin >> n >> k;
  vector<int>h(n);
  for(int i=0;i<n;i++)
    cin >> h.at(i);
  sort(h.begin(),h.end());
  int ans=1e9;
  for(int i=0;i<=n-k;i++){
    ans=min(ans,h.at(i+k-1)-h.at(i));
  }
  cout << ans << endl;
  return 0;
}