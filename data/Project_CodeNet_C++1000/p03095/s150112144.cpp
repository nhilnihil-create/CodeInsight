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
    int n;
    cin>>n;
    string s;
    cin>>s;
    V<ll> a(26,0);
    rep(i,n) a[s[i]-'a']++;
    ll ans=0;
    V<ll> tmp1;
    ll tmp2=0;
    rep(i,(1<<13)){
        //if(i==0) continue;
        ll cnt=1;
        rep(j,13){
            if(i>>j&1){
                cnt=(cnt*a[j])%mod;
            }
        }
        tmp1.push_back(cnt);
    }
    rep(i,(1<<13)){
        ll cnt=1;
        rep(j,13){
            if(i>>j&1){
                cnt=(cnt*a[j+13])%mod;
            }
        }
        tmp2=(tmp2+cnt)%mod;
    }
    for(ll cur:tmp1) ans=(ans+cur*tmp2%mod)%mod;
    ans--;
    if(ans<0) ans+=mod;
    out(ans);
}