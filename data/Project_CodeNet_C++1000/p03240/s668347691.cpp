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
    int n;cin>>n;
    vector<pair<ll,pair<ll,ll>>> p(n);
    rep(i,n){
        ll h,a,b;cin>>a>>b>>h;
        p[i]={h,{a,b}};
    }
    rep(cx,101)rep(cy,101){
        ll H=-1;
        rep(k,n){
            ll x,y,h;
            x=p[k].second.first;
            y=p[k].second.second;
            h=p[k].first;
            if(h==0)continue;
            H=h+abs(x-cx)+abs(y-cy);
            break;
        }
        bool ok=true;
        rep(k,n){
            ll x,y,h;
            x=p[k].second.first;
            y=p[k].second.second;
            h=p[k].first;
            ll th=max(H-abs(x-cx)-abs(y-cy),(ll)0);
            if(th!=h){
                ok=false;
                break;
            }
        }
        if(ok){
            cout<<cx<<" "<<cy<<" "<<H<<endl;
            return 0;
        }
    }
}