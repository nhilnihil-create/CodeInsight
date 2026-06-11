#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i <= (n); i++)
#define zep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define printa(x,m,n) for(int i = (m); i <= n; i++){cout << (x[i]) << " ";} cout<<endl;

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll a, b, c, x; cin >> a >> b >> c >> x;

    ll ans = 0;
    rep(i, 0, a){
        rep(j, 0, b){
            rep(k, 0, c){
                if(500*i+100*j+50*k == x)ans++;
            }
        }
    }
    print(ans) 
    return 0;
}