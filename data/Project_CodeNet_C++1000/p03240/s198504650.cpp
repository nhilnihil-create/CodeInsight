#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define cinf(n,x) for(int i=0;i<(n);i++)cin>>x[i];
#define ft first
#define sc second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(v) (v).begin(),(v).end()
#define LB(a,x) lb(all(a),x)-a.begin()
#define UB(a,x) ub(all(a),x)-a.begin()
#define mod 1000000007
#define FS fixed<<setprecision(15)
using namespace std;
typedef long long ll;
template<class T> using V=vector<T>;
using Graph = vector<vector<int>>;
using P=pair<ll,ll>;
typedef unsigned long long ull;
typedef long double ldouble;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

const ll INF=1e18;

int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    ll n,cx,cy,H;
    cin>>n;
    V<ll> x(n),y(n),h(n);
    rep(i,n) cin>>x[i]>>y[i]>>h[i];
    bool ok=0;
    for(ll i=0;i<=100;i++){//X
        for(ll j=0;j<=100;j++){//Y
            ll tmp=0;
            bool flag=1;
            rep(k,n){
                if(h[k]>0){
                    tmp=abs(x[k]-i)+abs(y[k]-j)+h[k];
                    break;
                }
            }
            rep(k,n){
                if(h[k]>0){
                    if(tmp!=abs(x[k]-i)+abs(y[k]-j)+h[k]){
                        flag=0;
                    }
                }else{
                    if(tmp-abs(x[k]-i)-abs(y[k]-j)>0){
                        flag=0;
                    }
                }
            }
            if(flag&&tmp>0){
                cx=i;
                cy=j;
                H=tmp;
                ok=1;
                break;
            }
        }
        if(ok) break;
    }
    cout<<cx<<' '<<cy<<' '<<H<<endl;
}