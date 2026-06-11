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

int main(){
  string S, T; cin >> S >> T;

  int N = S.length(), M = T.length();

  for (int i = N - M; i >= 0; i--){
    bool flag = true;
    for (int j = 0; j < M; j++){
      if (T[j] != S[i+j] && S[i+j] != '?') flag = false;
    }
    if (!flag) continue;

    for (int j = 0; j < M; j++) S[i+j] = T[j];
    for (int j = 0; j < N; j++){
      if (S[j] == '?') S[j] = 'a';
    }
    cout << S << endl;
    return 0;
  }

  cout << "UNRESTORABLE" << endl;

  return 0;
}
