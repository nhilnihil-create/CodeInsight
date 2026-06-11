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

int N, V[int(1e5+5)];
Pii cnt1[int(1e5+5)], cnt2[int(1e5+5)];

int main(){
  cin >> N;
  for (int i = 0; i < N; i++){
    cin >> V[i];
    if (i % 2 == 0){
      cnt1[V[i]].fi++;
    }else{
      cnt2[V[i]].fi++;
    }
  }

  for (int i = 0; i <= 1e5; i++){
    cnt1[i].se = i;
    cnt2[i].se = i;
  }
  sort(cnt1, cnt1 + int(1e5+1), greater<Pii>());
  sort(cnt2, cnt2 + int(1e5+1), greater<Pii>());

  int ans;
  if (cnt1[0].se != cnt2[0].se){
    ans = N - (cnt1[0].fi + cnt2[0].fi); 
  }else{
    ans = N - max(cnt1[1].fi+cnt2[0].fi, cnt1[0].fi+cnt2[1].fi);
  }
  cout << ans << endl;


  return 0;
}
