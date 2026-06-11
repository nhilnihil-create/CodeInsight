#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(ll i=0;i<n;++i)
#define INF (1ll<<60)
#define mod 1000000007
#define P pair<ll,ll>
#define Graph vector<vector<ll>>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

vector<ll> sum;
void pre_process(vector<ll> &a,vector<ll> &s){//累積和のvector
    ll n=(ll)a.size();
    s.assign(n+1,0);
    for(ll i=0;i<n;i++){
        s[i+1]=s[i]+a[i];
    }
}

int main(){
    ll N,C;cin>>N>>C;
    vector<ll> need(200010,0);
    
    vector<vector<P>> p(C);
    rep(i,N){
        ll s,t,c;cin>>s>>t>>c;c--;
        p[c].push_back({s,t});
    }
    rep(i,C) sort(p[i].begin(),p[i].end());


    rep(i,C){
        rep(j,p[i].size()){
            need[2*p[i][j].first-1]++;
            need[2*p[i][j].second]--;
        }
    }

    pre_process(need,sum);

    rep(i,C){
        rep(j,(ll)(p[i].size())-1){
            if(p[i][j].second==p[i][j+1].first){
                sum[2*p[i][j].second]--;
            }
        }
    }

    ll ans=1;
    rep(i,200011){
        chmax(ans,sum[i]);
    }
    
    cout<<ans<<endl;
    return 0;
}