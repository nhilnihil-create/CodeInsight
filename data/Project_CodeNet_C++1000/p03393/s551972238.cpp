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

string S;
bool used[26];

int main(){
  cin >> S;

  int N = S.length();
  for (int i = 0; i < N; i++){
    used[S[i] - 'a'] = true;
  }

  if (N < 26){
    for (int i = 0; i < 26; i++){
      if (used[i]) continue;
      char now = 'a' + i;
      S += now;
      cout << S << endl;
      return 0;
    }
  }

  fill(used, used + 26, false);

  for (int i = 25; i >= 1; i--){
    used[S[i]-'a'] = true;
    if (S[i - 1] > S[i]) continue;
    
  
    for (int j = 0; j < i-1; j++) cout << S[j];
    
    int now = S[i-1] - 'a'; 
    for (int j = now; j < 26; j++){
      if (!used[j]) continue;
      char C = j + 'a';
      cout << C << endl;
      return 0;
  }
  }

  cout << -1 << endl;
  return 0;
}
