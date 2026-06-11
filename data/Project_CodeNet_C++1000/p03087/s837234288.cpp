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

int N, Q;
string S;
int cnt[int(1e5+5)];

int main(){
  cin >> N >> Q;
  cin >> S;
  for (int i = 2; i <= N; i++){
    cnt[i] = cnt[i-1];
    if (S[i-2] == 'A' && S[i-1] == 'C') cnt[i]++;
  }

  for (int i = 0; i < Q; i++){
    int L, R; cin >> L >> R;
    int ans = cnt[R] - cnt[L-1];
    if (L > 1 && S[L-1] == 'C' && S[L-2] == 'A') ans--;
    cout << ans << endl;
  }

  return 0;
}
