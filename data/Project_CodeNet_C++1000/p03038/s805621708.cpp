#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> Pii;
typedef pair<int, ll> Pil;
typedef pair<ll, ll> Pll;
typedef pair<ll, int> Pli;
typedef vector < vector<ll> > Mat;

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

int N, M;
priority_queue <ll> que;
ll A[int(1e5+5)];
Pll P[int(1e5+5)];

int main(){
  cin >> N >> M;
  for (int i = 0; i < N; i++){
    cin >> A[i]; que.push(A[i]);
  }
  for (int i = 0; i < M; i++){
    ll B, C; cin >> B >> C;
    P[i] = {C, B};
  }
  sort(P, P + M, greater<Pll>());

  ll cnt = 0;
  for (int i = 0; i < M; i++){
    for (int j = 0; j < P[i].se; j++) que.push(P[i].fi);
    cnt += P[i].se;
    if (cnt >= N) break;
  }

  ll ans = 0;
  for (int i = 0; i < N; i++){
    ans += que.top(); que.pop();
  }
  cout << ans << endl;

  return 0;
}
