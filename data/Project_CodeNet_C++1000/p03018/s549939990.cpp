#include <bits/stdc++.h>
#define int long long
using namespace std;

string A;
int cnt;
int ans;

void solve(int now) {
  if(now < 0) return;
  if(A[now] == 'A') {
    ans += cnt;
    solve(now - 1);
  }else if(A[now] == 'C' && now > 0 && A[now - 1] == 'B') {
    cnt++;
    solve(now - 2);
  }else {
    cnt = 0;
    solve(now - 1);
  }
}

int32_t main() {
  cin >> A;
  solve(A.size() - 1);
  cout << ans << "\n";
}