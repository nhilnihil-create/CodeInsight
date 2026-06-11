#include<bits/stdc++.h>
using namespace std;
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(c) (c).rbegin(),(c).rend()
#define mp make_pair
#define endl '\n'
#define vec vector<ll>
#define mat vector<vector<ll> >
#define fi first
#define se second
typedef int ll;
typedef pair<ll,ll> pll;
typedef long double ld;
const ll inf=1e9+7;
const ll mod=998244353;
signed main(){
    string s;cin>>s;
    ll n=s.size();
    vector<ll>ma(1LL<<26,-1);
    ma[0]=0;
    ll now=0;
    ll ans=n;
    rep(i,n){
        now^=(1LL<<(s[i]-'a'));
        ll tmp=inf;
        rep(j,26){
            if(ma[(1LL<<j)^now]!=-1){
                tmp=min(tmp,ma[(1LL<<j)^now]+1);
            }
        }
        if(ma[now]!=-1){
            tmp=min(tmp,ma[now]);
        }
        if(tmp!=inf){
            ma[now]=tmp;
            if(i==n-1){
                ans=min(ans,tmp);
            }
        }
        //cout<<tmp<<endl;
    }
    if(ans==0)ans++;
    cout<<ans<<endl;
}