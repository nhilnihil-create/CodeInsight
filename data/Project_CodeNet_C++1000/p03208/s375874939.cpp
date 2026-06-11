#include <bits/stdc++.h>
using namespace std;

int main(){
  
  int n,k;
  cin >> n >> k;
  
  vector<int> h(n);
  
  for ( int i = 0 ; i < n ; i++){
    cin >> h[i];
  }
  
  sort(h.begin(),h.end());
  
  int ans = 1000000001;
  
  for ( int i = 0; i <= n-k ; i++){
    //cout << ans << ' ' << abs(h[i]-h[i+k-1]) << endl;
    ans = min(ans,abs(h[i]-h[i+k-1]));
  }
  
  cout << ans << endl;
  
}