#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(ll)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define rep2(i,j,n) for(int j=i;j<n;j++)
#define rep3(i,j,n) for(int j=i;j<=n;j++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    ll n,m;cin>>n>>m;
    vector<pair<ll,ll>> p(m);
    vector<vector<ll>> x(n+10);
    rep(i,m){
        ll a,b;cin>>a>>b;
        p[i]={a,b};
        x[a-1].push_back(b);
    }
    rep(i,n) sort(x[i].begin(),x[i].end());
    rep(i,m){
        ll a=p[i].first,b=p[i].second;
        string P=to_string(a);
        while(P.size()<6) P="0"+P;
        auto itr= lower_bound(x[a-1].begin(),x[a-1].end(),b);
        ll k=itr-x[a-1].begin();
        k++;
        string Y=to_string(k);
        while(Y.size()<6) Y="0"+Y;
        cout<<P<<Y<<endl;
    }
}
