#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    int n,K;cin>>n>>K;
    vector<pair<ll,ll>> p(n);
    vector<ll> X(n),Y(n);
    rep(i,n){
        cin>>p[i].first>>p[i].second;
        X[i]=p[i].first;Y[i]=p[i].second;
    }
    ll res=(1e+18)*5;
    rep(i,n)rep(j,n)rep(l,n)rep(r,n){
        if(i>=l||j>=r)continue;
        ll x1=X[i],y1=Y[j],x2=X[l],y2=Y[r];
        if(x1>x2)swap(x1,x2);
        if(y1>y2)swap(y1,y2);
        ll buf=(y2-y1)*(x2-x1);
        ll tot=0;
        rep(k,n){
            ll x=p[k].first,y=p[k].second;
            if(x1<=x&&x<=x2&&y1<=y&&y<=y2)tot++;
        }
        if(tot>=K)chmin(res,buf);
    }
    cout<<res<<endl;
}