#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repo(i,n) for(int i = 1; i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define np next_permutation
#define umap unordered_map
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define mod 1000000007
#define pi acos(-1.0)
ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }
ll jou(ll N, ll P){if(P==0) return 1;
    if(P%2==0){ll t = jou(N, P/2);return t*t % mod;
    }return (N * jou(N, P-1)) % mod;}  //jou(n,mod-2)で逆元
//intの最大値2147483647 ≒ 2×10^9
//long longの最大値9223372036854775807 ≒ 9×10^18
//'0'+=16;        で大文字に
//'大文字'+=32;    で小文字に
//  cout << fixed << setprecision (20);   小数点以下2０桁まで
//実行時間制約2秒では２×10^8回くらいまで計算できる


int main() {
  ll n;
  cin>>n;
  
  deque<ll> que;

  que.pb(3);
  que.pb(5);
  que.pb(7);
  
  ll ans=0;
  
  // BFS 開始 (キューが空になるまで探索を行う)
  while (!que.empty()) {
    ll v = que.front(); // キューから先頭頂点を取り出す
    que.pop_front();

    if(v>n) {
      cout << ans << endl;
      return 0; 
    }
    
    string s=to_string(v);
    int m=s.size();
    bool san=false;
    bool go=false;
    bool nana=false;
    rep(i,m){
      if(s[i]=='3') san=true;
      if(s[i]=='5') go=true;
      if(s[i]=='7') nana=true;      
    }
    if(san && go && nana) ans++;
    
    // 新たな白色頂点 nv について距離情報を更新してキューに追加する
    que.pb(v*10+3);
    que.pb(v*10+5);
    que.pb(v*10+7);
  }

}
