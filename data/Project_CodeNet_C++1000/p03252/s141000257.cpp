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

string S, T;
vector <int> s[26], t[26];

int main(){
  cin >> S >> T;
  for (int i = 0; i < S.length(); i++){
    s[S[i] - 'a'].push_back(i);
    t[T[i] - 'a'].push_back(i);
  }

  for (int i = 0; i < 26; i++){
    bool flag = false;
    for (int j = 0; j < 26; j++){
      if (s[i] == t[j]) flag = true;
    }
    if (flag) continue;
    No(); return 0;
  }
  Yes();
  return 0;
}
