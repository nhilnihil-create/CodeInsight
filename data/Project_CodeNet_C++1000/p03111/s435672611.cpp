#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const ll M = 1e15 + 7;
int si[] = {-1, 0, 1, 0};
int sj[] = {0, -1, 0, 1};

int n, A, B, C;
vector<int> l(10,0);

ll dfs(int cur, int a, int b, int c){
  if (cur == n) {
    if (a == 0 || b == 0 || c == 0) return M;
    else return abs(a-A) + abs(b-B) + abs(c-C) - 30;
  }
  ll ret0 = dfs(cur+1, a, b, c);
  ll ret1 = dfs(cur+1, a+l[cur], b, c) + 10;
  ll ret2 = dfs(cur+1, a, b+l[cur], c) + 10;
  ll ret3 = dfs(cur+1, a, b, c+l[cur]) + 10;
  
  return min(ret0,min(ret1,min(ret2,ret3)));
}

int main() {
  cin >> n >> A >> B >> C;
  rep(i,n) cin >> l[i];
  cout << dfs(0,0,0,0) << endl;
  return 0;
}
