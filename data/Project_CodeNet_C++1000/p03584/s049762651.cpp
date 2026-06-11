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
const ll inf=1e9+7;
const ll mod=998244353;
int main(){
    ll n,k;cin>>n>>k;
    vector<ll>a(n);
    vector<ll>b(n);
    rep(i,n)cin>>a[i]>>b[i];
    ll ans=0;
    for(int i=29;i>=0;i--){
        ll cnt=0;
        if(((1<<i)&k)==0)continue;
        rep(l,n){
            bool f=1;
            for(int j=29;j>=i;j--){
                if((a[l]&(1<<j))>(k&(1<<j)))f=0;
            }
            if((1<<i)&a[l])f=0;
            if(f)cnt+=b[l];
        }
        ans=max(ans,cnt);
    }
    ll cnt=0;
    rep(i,n){
        bool f=1;
        for(int j=29;j>=0;j--){
            if((a[i]&(1<<j))>(k&(1<<j)))f=0;
        }
        if(f)cnt+=b[i];
    }
    ans=max(ans,cnt);
    cout<<ans<<endl;
}