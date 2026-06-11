#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
using namespace std;
typedef long long ll;
int main() {
  int N; cin >> N;
  vector<int> a(N+1, 0); 
  cin >> a[0]; int b = a[0];
  int count = 1;
  int ans = 0;
  for(int i = 1; i<N; i++) {
    cin >> a[i];
    if(b==a[i]) {count++;}
    else {ans += count/2; b = a[i]; count = 1;} 

  }
  ans += count/2;
  cout << ans << endl;
}