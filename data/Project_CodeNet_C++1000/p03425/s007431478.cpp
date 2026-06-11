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

int N;
char C[5] = {'M', 'A', 'R', 'C', 'H'};
ll cnt[5];

int main(){
  cin >> N;
  for (int i = 0; i < N; i++){
    string S; cin >> S;
    for (int j = 0; j < 5; j++){
      if (S[0] == C[j]) cnt[j]++;
    }
  }
  ll ans = 0;
  for (int i = 0; i < 5; i++){
    for (int j = i + 1; j < 5; j++){
      for (int k = j + 1; k < 5; k++){
        ans += cnt[i] * cnt[j] * cnt[k];
      }
    }
  }
  cout << ans << endl;


  return 0;
}
