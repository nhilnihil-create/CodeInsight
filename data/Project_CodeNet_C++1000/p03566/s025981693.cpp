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
const ll mod=1e9+7;
int main(){
    ll n;cin>>n;
    vector<ll>t(n+1);
    vector<ll>l(n+2);
    vector<ll>r(n+2);
    vector<ll>v(n+2);
    rep(i,n)cin>>t[i+1];
    rep(i,n)cin>>v[i];
    REP(i,1,n+1){
        t[i]+=t[i-1];
    }
    rep(i,n){
        l[i]=t[i];
        r[i]=t[i+1];
    }
    l[n+1]=t[n];
    r[n+1]=t[n];
    double now=0.0;
    double last=0.0;
    double ans=0.0;
    while(now<t[n]){
        now+=0.5;
        double mi=inf;
        rep(i,n+2){
            double res;
            if(now<=l[i])res=v[i]+(double)l[i]-now;
            if(now>=l[i]&&now<=r[i])res=v[i];
            if(now>=r[i])res=v[i]+now-(double)r[i];
            mi=min(mi,res);
        }
        ans+=(last+mi)*0.25;
        last=mi;
    }
    cout<<fixed<<setprecision(8)<<ans<<endl;
}