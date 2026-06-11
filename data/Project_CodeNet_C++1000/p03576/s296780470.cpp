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
//#define mod 998244353
#define FS fixed<<setprecision(15)
using namespace std;
typedef long long ll;
const double pi=3.141592653589793;
template<class T> using V=vector<T>;
using Graph = vector<vector<int>>;
using P=pair<ll,ll>;
typedef unsigned long long ull;
typedef long double ldouble;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline void out(T a){ cout << a << '\n'; }
void YN(bool ok){if(ok) cout << "Yes" << endl; else cout << "No" << endl;}
//void YN(bool ok){if(ok) cout << "YES" << endl; else cout << "NO" << endl;}


const ll INF=1e18;
const int mx=200005;

int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    ll n,K;
    cin>>n>>K;
    V<ll> x(n),y(n);
    V<P> p(n);
    rep(i,n){
        cin>>x[i]>>y[i];
        p[i]=make_pair(x[i],i);
    }
    sort(all(p));
    ll ans=5*INF;
    rep(i,n){
        for(int j=i;j<n;j++){
            if(j-i+1<K) continue;
            ll w=p[j].ft-p[i].ft;
            V<ll> tmp;
            for(int k=i;k<=j;k++){
                tmp.push_back(y[p[k].sc]);
            }
            sort(all(tmp));
            for(int k=0;k<(int)tmp.size()-K+1;k++){
                ll h=tmp[k+K-1]-tmp[k];
                chmin(ans,h*w);
            }
        }
    }
    out(ans);
}
