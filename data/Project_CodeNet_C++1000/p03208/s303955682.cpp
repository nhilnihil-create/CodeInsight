#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,k;
  cin >> n >> k;
  vector<int> h(n);
  for(int i = 0; i < n; i++){
    cin >> h[i];
  }
  sort(h.begin(),h.end());
  int ans = h[n-1] - h[0];
  for(int i = 0; i < n-k+1; i++){
    ans = min(ans,h[i+k-1]-h[i]);
  }
  cout << ans << endl;
}