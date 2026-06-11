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

int A, B, Q; ll X;
ll S[int(1e5+5)], T[int(1e5+5)];

int SL, SR, TL, TR;

int Solve(){
  SL = 0; SR = A + 1;
  while (SR - SL > 1){
    int now = (SL + SR) / 2;
    if (S[now] <= X) SL = now;
    else SR = now;
  }
  TL = 0; TR = B + 1;
  while (TR - TL > 1){
    int now = (TL + TR) / 2;
    if (T[now] <= X) TL = now;
    else TR = now; 
  }

  return 0;
}

int main(){
  cin >> A >> B >> Q;
  S[0] = -1e10;
  for (int i = 1; i <= A; i++) cin >> S[i];
  S[A + 1] = 1e11;

  T[0] = -1e10;
  for (int i = 1; i <= B; i++) cin >> T[i];
  T[B + 1] = 1e11;

  for (int i = 0; i < Q; i++){
    cin >> X;
    Solve();

    ll ans = max(S[SR] - X, T[TR] - X);
    ans = min(ans, max(X - S[SL], X - T[TL]));

    ans = min(ans, (T[TR] - X) * 2 + (X - S[SL]));
    ans = min(ans, (X - S[SL]) * 2 + (T[TR] - X));
    ans = min(ans, (S[SR] - X) * 2 + (X - T[TL]));
    ans = min(ans, (X - T[TL]) * 2 + (S[SR] - X));

    cout << ans << endl;
  }

  return 0;
}
