#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> P;
typedef vector<vector<int>> Matrix;

static const int INF = 1<<29;
int N, A, B, C;
int l[8];
int dfs(int a, int b, int c, int i){
  int minv = INF;
  if (i == N) return ((a==0 || b==0 || c==0) ? INF : abs(a - A) + abs(b - B) + abs(c - C) - 30);
  minv = min(minv, dfs(a + l[i], b, c, i + 1) + 10);
  minv = min(minv, dfs(a, b + l[i], c, i + 1) + 10);
  minv = min(minv, dfs(a, b, c + l[i], i + 1) + 10);
  minv = min(minv, dfs(a, b, c, i + 1));
  return minv;
}

int main(){
  cin >> N >> A >> B >> C;
  rep(i, N)cin >> l[i];
  cout << dfs(0, 0, 0, 0) << endl;
}