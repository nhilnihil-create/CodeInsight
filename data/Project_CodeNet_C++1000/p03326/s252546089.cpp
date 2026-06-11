#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define cinf(n,x) for(int i=0;i<(n);i++)cin>>x[i];
#define max3(a,b,c) max(max(a,b),c)
#define min3(a,b,c) min(min(a,b),c)
#define ft first
#define sc second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(v) (v).begin(),(v).end()
#define mod 1000000007
using namespace std;
typedef long long ll;
template<class T> using V=vector<T>;
using Graph = vector<vector<int>>;
using P=pair<ll,ll>;
typedef unsigned long long ull;
typedef long double ldouble;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//V,P(大文字)使用不可

const ll INF=1e18;

signed main(){
    int n,m;
    cin>>n>>m;
    V<ll> x(n),y(n),z(n);
    rep(i,n) cin>>x[i]>>y[i]>>z[i];
    ll ans=0;
    for(int i=0;i<8;i++){
        string t;
        for(int j=0;j<3;j++){
            if(i>>j&1) t+='+';
            else t+='-';
        }
        V<pair<ll,int>> p;
        for(int j=0;j<n;j++){
            ll cnt=0;
            for(int k=0;k<3;k++){
                if(k==0){
                    if(t[k]=='+') cnt+=x[j];
                    else cnt-=x[j];
                }else if(k==1){
                    if(t[k]=='+') cnt+=y[j];
                    else cnt-=y[j];
                }else{
                    if(t[k]=='+') cnt+=z[j];
                    else cnt-=z[j];
                }
            }
            p.push_back(make_pair(cnt,j));
        }
        sort(all(p),greater<pair<ll,int>>());
        ll a=0,b=0,c=0;
        for(int j=0;j<m;j++){
            a+=x[p[j].sc];
            b+=y[p[j].sc];
            c+=z[p[j].sc];
        }
        chmax(ans,abs(a)+abs(b)+abs(c));
    }
    cout<<ans<<endl;
}