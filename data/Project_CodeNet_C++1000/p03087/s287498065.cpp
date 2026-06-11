#include<bits/stdc++.h>
 
#define rep(i,n) for(ll i = 0;i < n;++i)
#define all(v) v.begin(),v.end()
using namespace std;
using ll = long long;
typedef pair<int,int> P;
 
const int INF = 1001001001;
const long double PI = (acos(-1));
const int mod = 1e9+7;
const int vx[6] = {0,1,0,-1,1,-1};
const int vy[6] = {1,0,-1,0,1,1};




int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n,q;
    string s;
    cin >> n >> q >> s;
    vector<ll> ac(n,0);
    ll a = 0;
    rep(i,s.length()){
        if(i == s.length()-1) {
            ac[i] = a;
            break;
        }
        if(s[i] == 'A' && s[i+1] == 'C'){
            ac[i] = a;
            a++;
        }else {
            ac[i] = a;
        }
    }
    rep(i,q){
        ll l,r;
        cin >> l >> r;
        ll t,tt;
        t = ac[l-1];
        tt = ac[r-1];
        int ans = tt-t;
        cout << ans << endl;
    }

    cout << endl;
    return 0;
}
