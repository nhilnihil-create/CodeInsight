#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<cassert>
#include<complex>
#include<numeric>
using namespace std;

typedef long long ll;
typedef unsigned long long ul;
typedef unsigned int ui;
typedef pair<int, int>P;
typedef pair<ll, ll> LP;
typedef long double ld;
typedef pair<ld, ld> LDP;
typedef vector<vector<ll>> mat;
typedef vector<int> vec;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define all(v) (v).begin(),(v).end()
const ll mod = 1000000007;
const ll INF = mod * mod;
const ld eps = 1e-12;
const ld pi = acos(-1.0);
//int qp(int a,ll b){int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);return ans;}
ll qp(ll a,ll b,int mo){int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);return ans;}
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };



void solve() {
    ll a, b, c, d, e , m, n, k, x, y, l,r,t;
    string s;
    ll ans = 0;
    double dans = 0;
    string sans = "Yes";
    vector<ll> ar;

    cin >> n >> m >> x >> y;

    ll x_max = -101;
    ll y_min = 101;

    rep(i, n){
        ll tm;
        cin >> tm;
        x_max = max(x_max, tm);
    }

    rep(i,m){
        ll tm;
        cin >> tm;
        y_min = min(y_min,tm);
    }

    sans = "War";

    if(y<x){}
    else{
        for(ll i=x+1; i <=y; i++){
            if(x_max < i && i <= y_min){
                sans = "No War";
                break;
            }
        }
    }





    // std::cout << ans << endl; 

    std::cout << sans << endl; 
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(10);
    solve();
    // stop
        return 0;
}