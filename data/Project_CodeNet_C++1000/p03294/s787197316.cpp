#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int N;
  cin >> N;
  int a[N];
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  int ans = 0;
  for (int i = 0; i < N; i++) {
    ans += a[i] - 1;
  }
  cout << ans << endl;  
  return 0;
}