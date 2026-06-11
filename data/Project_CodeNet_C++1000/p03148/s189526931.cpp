#include<bits/stdc++.h>
using namespace std;
#define ALL(x) x.begin(),x.end()
#define rep(i,n) for(int i=0;i<n;i++)
#define debug(v) cout<<#v<<":";for(auto x:v){cout<<x<<' ';}cout<<endl; 
#define INF 1000000000
#define mod 1000000007
typedef long long ll;
const ll LINF = 1001002003004005006ll;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    ll n,k;cin>>n>>k;
    vector<pair<ll,ll>> v(n);
    rep(i,n){
        ll t,d;cin>>t>>d;t--;
        v[i]=make_pair(d,t);
    }
    sort(ALL(v));
    ll ans=0,var=0;
    vector<pair<ll,ll>> vv;
    vector<pair<ll,ll>> rem;
    vector<ll> cnt(n,0);
    rep(i,k){
        ans+=v[n-i-1].first;
        if(cnt[v[n-i-1].second]==0) var++;
        cnt[v[n-i-1].second]++;
        vv.push_back(v[n-i-1]);
    }
    ans+=var*var;//答えの暫定値
    for(int i=k;i<n;i++){
        rem.push_back(v[n-i-1]);
    }
    reverse(ALL(vv));

    // for(auto x:vv){
    //     cout<<x.first<<' ';
    // }cout<<endl;
    // for(auto x:rem){
    //     cout<<x.first<<' ';
    // }cout<<endl;
    
    int idx=0;
    ll tmp=ans;
    for(auto x:rem){
        
        if(idx>=k) break;
        if(cnt[x.second]>0) continue;

        while(cnt[vv[idx].second]==1&&idx<k){
            idx++;
        }
        if(idx>=k) break;
        cnt[vv[idx].second]--;
        cnt[x.second]++;
        tmp-=vv[idx].first;
        tmp+=x.first;
        tmp+=(var+1)*(var+1)-var*var;
        ans=max(ans,tmp);
        var++;
        idx++;
    }
    //debug(cnt);
    cout<<ans<<endl;
    return 0;
}
