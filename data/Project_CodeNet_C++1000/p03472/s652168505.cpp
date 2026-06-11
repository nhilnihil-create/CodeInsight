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

int N; ll H;
priority_queue <Pli> que;
int main(){
  cin >> N >> H;
  for (int i = 0; i < N; i++){
    ll A, B; cin >> A >> B;
    que.push({A, 0});
    que.push({B, 1});
  }

  ll ans = 0, rest = H;
  while (!que.empty()){
    Pli Q = que.top(); que.pop();
    if (Q.se == 1){
      rest -= Q.fi; ans++;
      if (rest <= 0){
        cout << ans << endl;
        return 0;
      }
    }else{
      ans += rest / Q.fi;
      if (rest % Q.fi != 0) ans++;
      cout << ans << endl;
      return 0;
    }
  }


  return 0;
}
