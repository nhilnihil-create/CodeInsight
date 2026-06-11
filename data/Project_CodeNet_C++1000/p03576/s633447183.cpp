#include<bits/stdc++.h>
using namespace std;
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll inf=1e9+7;
const ll mod=1e9+7;
int main(){
    ll mi=4*(inf-7)*(inf-7);
    ll n,kk;cin>>n>>kk;
    vector<pll>p(n);
    rep(i,n){
        ll x,y;cin>>x>>y;
        p[i]=mp(x,y);
    }
    if(kk==2){
        rep(i,n){
            REP(j,i+1,n){
                mi=min(mi,abs((p[i].first-p[j].first)*(p[i].second-p[j].second)));
            }
        }
        cout<<mi<<endl;
        return 0;
    }
    if(kk==3){
        rep(i,n){
            REP(j,i+1,n){
                REP(k,j+1,n){
                    ll X=max(max(p[i].first,p[j].first),p[k].first);
                    ll Y=max(max(p[i].second,p[j].second),p[k].second);
                    ll x=min(min(p[i].first,p[j].first),p[k].first);
                    ll y=min(min(p[i].second,p[j].second),p[k].second);
                    mi=min((X-x)*(Y-y),mi);
                }
            }
        }
        cout<<mi<<endl;
        return 0;
    }
    rep(i,n){
        REP(j,i+1,n){
            REP(k,j+1,n){
                REP(l,k+1,n){
                    ll X=max(max(p[i].first,p[j].first),max(p[k].first,p[l].first));
                    ll Y=max(max(p[i].second,p[j].second),max(p[k].second,p[l].second));
                    ll x=min(min(p[i].first,p[j].first),min(p[k].first,p[l].first));
                    ll y=min(min(p[i].second,p[j].second),min(p[k].second,p[l].second));
                    ll cnt=0;
                    rep(m,n){
                        if(p[m].first<=X&&p[m].first>=x&&p[m].second>=y&&p[m].second<=Y)cnt++;
                    }
                    if(cnt==kk)mi=min((X-x)*(Y-y),mi);
                }
            }
        }
    }
    cout<<mi<<endl;
}