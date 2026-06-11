#include <bits/stdc++.h>
using namespace std;

#define sz(x) int(x.size())
#define pii pair<int, int>
#define All(x) (x).begin(), (x).end()
#define mp make_pair
#define Task "abc"

typedef long long ll;
const int maxn = 1e4 + 10;
const ll mod = 1e9 + 7;

int n, m;
int c[] = {2, 5, 5, 4, 5, 6, 3, 7, 6};
int num[10], cost[10], ma[8];
int f[maxn], tr[maxn];

void Trace(int i){
  if (i == 0) return;
  int t = tr[i];
  cout << ma[i - t];
  Trace(t);
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(NULL);
//  freopen(Task".inp", "r", stdin); freopen(Task".out", "w", stdout);
  cin >> n >> m;
  for (int i = 0; i < 10; ++i){
    cost[i+1] = c[i];
  }
  for (int i = 0; i < m; ++i){
    cin >> num[i];
    ma[cost[num[i]]] = max(ma[cost[num[i]]], num[i]);
  }
  sort(num, num + m);
  const int inf = 2e9;
  fill(f, f + maxn, -inf);
  f[0] = 0;
  for (int i = 2; i <= n; ++i) for (int j = 0; j < m; ++j){
    int l = cost[num[j]];
    if (num[j] != ma[l]) continue;
    if (i < l) continue;
    if (f[i] <= f[i-l] + 1){
      f[i] = f[i-l] + 1;
      tr[i] = i-l;
    }
  }
  Trace(n);
return 0;
}


