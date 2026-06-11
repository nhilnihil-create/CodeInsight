#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep2(i,a,b) for(int i=(a);i<(b);++i)


int main() {
  int H,W,D;
  cin >> H >> W >> D;
  int a;
  vector<vector<int>> A(H,vector<int>(W)),lis(H*W,vector<int>(2,0));
  rep(i,H)rep(j,W) {
    cin >> a;
    a--;
    A[i][j]=a;
    lis[a] = {i,j};
  }
  vector<int> cost(H*W,0);
  rep2(i,D,H*W) {
    auto t = lis[i-D], n = lis[i];
    cost[i] += cost[i-D] + abs(t[0]-n[0]) + abs(t[1]-n[1]);
  }
    
  int Q,l,r;
  cin >> Q;
  rep(i,Q) {
    cin >> l >> r;
    l--;r--;
    cout << cost[r] - cost[l] << endl;
  }
} 