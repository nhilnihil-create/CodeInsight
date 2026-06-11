#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;

int ans = 0;

void dfs(vector<int> &A, vector<int> &B) {
  if (A.size() == B.size()) {
    int p = 1;
    rep(i,0,A.size()-1) {
      p *= A[i] + B[i];
    }
    if (p % 2 == 0) ans++;
    return;
  };

  rep(i,-1,1) {
    B.push_back(i);
    dfs(A, B);
    B.pop_back();
  }
}

int main() {
  int N;
  cin >> N;

  vector<int> A(N), B;
  rep(i,0,N-1) cin >> A[i];
  dfs(A, B);

  cout << ans << endl;
  return 0;
}
