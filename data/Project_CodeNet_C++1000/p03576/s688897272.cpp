#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define _GLIBCXX_DEBUG
#define fi first
#define se second

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vd = vector<double>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using vvd = vector<vd>;
using vvvi = vector<vvi>;
using vvvll = vector<vvll>;
using vvvd = vector<vvd>;

const double pi=acos(-1);
const ll MOD=1e9+7;
const ll INF=(1LL<<60);

int main() {
    int n,k;
    cin>>n>>k;
    vector<pair<ll,ll>> p;
    rep(i,n){
        ll x,y;
        cin>>x>>y;
        p.push_back({x,y});
    }
    ll ans=5e18;
    rep(i,n){
        rep(j,n){
            rep(l,n){
                rep(m,n){
                    ll xmin=min(p[i].fi,min(p[j].fi,min(p[l].fi,p[m].fi)));
                    ll ymin=min(p[i].se,min(p[j].se,min(p[l].se,p[m].se)));
                    ll xmax=max(p[i].fi,max(p[j].fi,max(p[l].fi,p[m].fi)));
                    ll ymax=max(p[i].se,max(p[j].se,max(p[l].se,p[m].se)));
                    int b=1;
                    int c=0;
                    rep(o,n){
                        if (xmin<=p[o].fi && xmax>=p[o].fi && ymin<=p[o].se && ymax>=p[o].se){
                            c++;
                        }
                    }
                    if (c>=k){
                        ans=min(ans,(xmax-xmin)*(ymax-ymin));
                    }
                }
            }
        }
    }
    cout<<ans<<endl;



    return 0;
}