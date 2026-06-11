#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> Pii;
typedef pair<int, ll> Pil;
typedef pair<ll, ll> Pll;
typedef pair<ll, int> Pli;

#define fi first
#define se second

const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll MOD3 = 1812447359;
const ll INF = 1ll << 62;
const double PI = 2 * asin(1);

void yes() {printf("yes\n");}
void no() {printf("no\n");}
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

int N, Dist[int(1e5+5)];
vector <int> Graph[int(1e5+5)];
ll DP[int(1e5+5)][2];
bool checked[int(1e5+5)][2];

ll Solve(int num, int color){
  if (checked[num][color]) return DP[num][color];
  checked[num][color] = true;
  ll ans = 1;

  for (int next : Graph[num]){
    if (Dist[num] > Dist[next]) continue;
    if (color == 0){
      ans *= (Solve(next, 0) + Solve(next, 1)) % MOD;
    }else{
      ans *= Solve(next, 0);
    }
    ans %= MOD;
  }
  return DP[num][color] = ans;
}


int main(){
  cin >> N;
  fill(Dist, Dist + N + 1, -1);
  for (int i = 0; i < N - 1; i++){
    int X, Y; cin >> X >> Y;
    Graph[X].push_back(Y);
    Graph[Y].push_back(X);
  }
  queue <int> que; que.push(1);
  Dist[1] = 0;
  while (!que.empty()){
    int Q = que.front(); que.pop();
    for (int next : Graph[Q]){
      if (Dist[next] != -1) continue;
      que.push(next);
      Dist[next] = Dist[Q] + 1; 
    }
  }
  cout << (Solve(1, 0) + Solve(1, 1)) % MOD << endl;
  return 0;
}
