#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; i++)
using P = pair <int, int>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
ll gcd(ll a,ll b) {return  b ? gcd(b,a%b) : a;}
const long long INF = 1LL << 60;
const int mod = 1000000007;
const double PI = acos(-1.0);
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};


main(){
    ll n,m;
    cin >> n >> m;
    vector<ll> a(n);
    rep(i,n)cin >> a[i];
    vector<ll> d(n);
    vector<ll> s(n);
    s[0]=a[0];
    rep(i,n-1){
         s[i+1] = s[i]+a[i+1];
    }
    rep(i,n){
         d[i]=s[i]%m;
    }
    map<ll,ll>mp;
    rep(i,n){
         mp[d[i]]++;
    }
    ll ans = 0;
    for(auto x :mp){
         if(x.first == 0) ans+=x.second;
         if(x.second >=2 ) {
              ans += x.second*(x.second-1)/2;
         }
    }
    cout << ans <<endl;
}
