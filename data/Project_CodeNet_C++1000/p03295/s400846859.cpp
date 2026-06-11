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

int main(){
    ll n,m;cin>>n>>m;
    vector<P> p(m);
    rep(i,m){
        ll a,b;cin>>a>>b;
        a--;b--;
        p[i]=make_pair(a,b);
    }
    sort(p.begin(),p.end());
    p.push_back({-1,-1});

    P Pair=make_pair(0,n-1);
    ll ans=0;
    rep(i,m+1){
        bool no=true;
        if(Pair.first<=p[i].first && p[i].first<Pair.second){
            Pair.first=p[i].first;
            no=false;
        }
        if(Pair.first<p[i].second && p[i].second<=Pair.second){
            Pair.second=p[i].second;
            no=false;
        }
        if(no==true || i==m){
            ans++;
            //cout<<"ch:"<<Pair.first<<" "<<Pair.second<<endl;
            Pair=p[i];
        }
    }

    cout<<ans<<endl;
    return 0;
}