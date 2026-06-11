#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rrep(i,n) for(int i=(int)(n-1);i>=0;i--)
#define FOR(i,n,m) for(int i=n;i<=(int)(m);i++)
#define RFOR(i,n,m) for(int i=(int)(n);i>=m;i--)
#define all(x) (x).begin(),(x).end()
#define sz(x) int(x.size())
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;
using namespace std;
vector<int> dy={1,0,-1,0};
vector<int> dx={0,1,0,-1};
template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}
int main(){
    int n,k;
    cin>>n>>k;
    vector<ll> sum(n+1);
    rep(i,n) {
        ll a;
        cin>>a;
        sum[i+1]=sum[i]+a;
    }
    
    vector<ll> beauty;
    FOR(r,1,n){
        FOR(l,0,r-1){
            beauty.push_back(sum[r]-sum[l]);
        }
    }
    
    //for(int x:beauty) cout<<x<<endl;
    
    int m=sz(beauty);
    vector<bool> check(m,true);
    rrep(d,41){
        int cnt=0;
        rep(i,m){
            if(!check[i]) continue;
            if(beauty[i]&(1ll<<d)) cnt++;
        }
        
        if(cnt<k) continue;
        
        rep(i,m){
            if(!(beauty[i]&(1ll<<d))) check[i]=false;
        }
        
        if(cnt==k) break;
        //cout<<d<<" "<<cnt<<endl;
    }
    
    ll ans=-1;
    int cnt=0;
    rep(i,m) if(check[i]) {
        if(ans==-1) ans=beauty[i];
        else ans &= beauty[i];
        cnt++;
        if(cnt==k) break;
    }
    cout<<ans<<endl;
}


