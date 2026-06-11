#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};

 
int main(){
  int n, k;
  cin >> n >> k;
  vector<int> h(n);
  for(int i=0; i<n; i++) cin >> h[i];
  sort(h.begin(), h.end());
  int ans = 1000000009;
  for(int i=0; i<=n-k; i++){
    ans = min(ans, h[i+k-1]-h[i]);
  }
  cout << ans << endl;
  return 0;
}
