#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
#define eb(t) emplace_back(t)
typedef long long ll;
typedef long long unsigned int llu;
ll INF = 1000000009;
ll MOD = 1000000007;

char s[310][310];

void solve(){

    ll n;
    cin >> n;
    rep(i,n){
        string st;
        cin >> st;
        rep(j,n){
            s[i][j]=st[j];
        }
    }

    ll ans = 0;
    rep(i,n){
        //移動水平距離i
        bool b=true;
        rep(p,n){
            for(ll q=0;q<p;q++){
                if(s[(p-i+n)%n][q]!=s[(q-i+n)%n][p]) b=false;
            }
        }
        if(b) ans += n;
    }

    cout << ans << endl;
    
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
