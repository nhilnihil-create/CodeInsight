#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (ll i = 0; i < (n); i++)
typedef pair<ll,ll> P;

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}

int main(){
    ll n, m;
    cin >> n >> m;

    vector<P> res(m);
    vector<vector<ll>> id(n,vector<ll>());

    rep(i,m){
        ll p,y;
        cin >> p >> y;
        p--;
        P pr(p,y);
        res[i] = pr;
        id[p].push_back(y);
    }


    rep(i,n){
        sort(id[i].begin(), id[i].end(), less<ll>());
    }


    rep(i,m){
        ll p, y;
        p = res[i].first;
        y = res[i].second;

        auto it = lower_bound(id[p].begin(), id[p].end(), y);
        ll d = distance(id[p].begin(), it);
        p++;

        string l = to_string(p);
        string r = to_string(d+1);

        if(l.size()<6){
            ll t = 6-l.size();
            rep(i, t){
                l = '0'+l;
            }
        }
        if(r.size()<6){
            ll t = 6-r.size();
            rep(i, t){
                r = '0'+r;
            }
        }

        cout << l << r << endl;
    }

    return 0;
}