#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define int long long
#define _GLIBCXX_DEBUG

int H, W;

void f(auto &A, auto q, int &n, int &ans) {
  if(n == H*W) return;
  queue<pair<int,int>> next;
  while(!q.empty()) {
    int i=q.front().first, j=q.front().second;
    q.pop();
    if(i>0 && !A[i-1][j]) {
      A[i-1][j] = true;
      next.push(make_pair(i-1, j));
      n++;
    }
    if(j>0 && !A[i][j-1]) {
      A[i][j-1] = true;
      next.push(make_pair(i, j-1));
      n++;
    }
    if(i<H-1 && !A[i+1][j]) {
      A[i+1][j] = true;
      next.push(make_pair(i+1, j));
      n++;
    }
    if(j<W-1 && !A[i][j+1]) {
      A[i][j+1] = true;
      next.push(make_pair(i, j+1));
      n++;
    }
  }
  ans++;
  
  f(A, next, n, ans);
}

signed main() {
  cin >> H >> W;
  vector<vector<bool>> A(H, vector<bool>(W));
  queue<pair<int,int>> q;
  int n=0, ans=0;
  rep(i, H) rep(j, W) {
    char k; cin >> k;
    A[i][j] = (k == '#' ? true : false);
    if(A[i][j]) {
      n++;
      q.push(make_pair(i, j));
    }
  }
  
  f(A, q, n, ans);

  cout << ans << endl;
}