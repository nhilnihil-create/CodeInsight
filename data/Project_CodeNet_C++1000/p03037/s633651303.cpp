#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using P = pair<int, int>;

const int INF = 1e9;
const int MOD = 1e9 + 7;

// 4近傍、8近傍
int dx[] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

int sum[100010];

int main() {
  int N, M;
  cin >> N >> M;
  int l[M], r[M];
  for (int i = 0; i < M; i++) {
    cin >> l[i] >> r[i];
  }

  for (int i = 0; i < M; i++) {
    sum[l[i]]++;
    sum[r[i]+1]--;
  }

 for (int i = 1; i < N + 1; i++) {
   sum[i] += sum[i-1];
 }

 int ans = 0;
 for (int i = 0; i < N + 1; i++) {
   if (sum[i] == M) ans++;
 }

 cout << ans << endl;
 return 0;
}