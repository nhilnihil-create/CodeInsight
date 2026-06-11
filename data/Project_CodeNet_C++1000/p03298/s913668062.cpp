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
    
    ll n;
    string s;
    cin >> n >> s;

    map<pair<string, string>, ll> mp;
    zep(bit, 0, (1LL << n)){
        string r = "", b = "";

        zep(i, 0, n){
            if(bit & (1LL << i)){
                r += s[i];
            }
            else{
                b += s[i];
            }
        }
        reverse(r.begin(), r.end());
        reverse(b.begin(), b.end());
        
        auto p = make_pair(b, r);
        if(mp.find(p) == mp.end())
            mp[p] = 0;
        mp[p]++;
    }

    ll ans = 0;
    zep(bit, 0, (1LL << n)){
        string r = "", b = "";

        zep(i, 0, n){
            if(bit & (1LL << i)){
                r += s[i+n];
            }
            else{
                b += s[i+n];
            }
        }
        auto p = make_pair(r, b);
        if(mp.find(p) != mp.end())
            ans += mp[p];
    }
    print(ans)

    return 0;
}