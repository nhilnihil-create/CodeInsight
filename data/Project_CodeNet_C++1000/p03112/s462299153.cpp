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

int A, B, Q;
ll S[int(1e5 + 5)], T[int(1e5 + 5)];
ll X;
int SL, SR, TL, TR;

int Binary(){
  SL = 0; SR = A + 1;
  while (SR - SL > 1){
    int now = (SL + SR) / 2;
    if (S[now] < X) SL = now;
    else SR = now; 
  }

  TL = 0; TR = B + 1;
  while (TR - TL > 1){
    int now = (TL + TR) / 2;
    if (T[now] < X) TL = now;
    else TR = now;
  }
  return 0;
}

int main(){
  cin >> A >> B >> Q;
  S[0] = -1e16; T[0] = -1e16;
  for (int i = 1; i <= A; i++) cin >> S[i];
  for (int i = 1; i <= B; i++) cin >> T[i];
  S[A + 1] = 1e16; T[B + 1] = 1e16;


  for (int i = 0; i < Q; i++){
    cin >> X;
    Binary();

    ll ans = max(T[TR] - X, S[SR] - X);
    ans = min(ans, max(X - T[TL], X - S[SL]));

    ans = min(ans, (T[TR] - S[SL]) + min(T[TR] - X, X - S[SL]));
    ans = min(ans, (S[SR] - T[TL]) + min(S[SR] - X, X - T[TL]));

    cout << ans << endl;
  }


  return 0;
}
