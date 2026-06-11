#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
using namespace std;
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(c) (c).rbegin(),(c).rend()
#define mp make_pair
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;
const ll inf=1e9+7;
const ll mod=998244353;
int main(){
    ll n,C;cin>>n>>C;
    vector<ll>a(100010);
    vector<vector<pll> >b(C);
    rep(i,n){
        ll s,t,c;cin>>s>>t>>c;
        c--;
        b[c].pb(mp(s,t));
    }
    rep(i,C){
        sort(all(b[i]));
        ll last=0;
        rep(j,b[i].size()){
            //cout<<i<<' '<<b[i][j].first<<' '<<b[i][j].second<<endl;
            if(last==b[i][j].first){
            }else{
                a[b[i][j].first]++;
                if(last)a[last+1]--;
            }
            last=b[i][j].second;
        }
        if(last)a[last+1]--;
    }
    ll ma=1;
    REP(i,1,100010){
        a[i]+=a[i-1];
    }
    rep(i,100010){
        ma=max(a[i],ma);
    }
    cout<<ma<<endl;
}