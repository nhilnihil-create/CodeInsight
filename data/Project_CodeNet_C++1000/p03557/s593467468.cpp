#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
//using namespace boost::multiprecision;
typedef long long int ll;
typedef long double ld;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
bool pairCompare(const pair<double,ll>& firstElof, const pair<double,ll>& secondElof){
    return firstElof.first < secondElof.first;
}
bool pairCompareSecond(const pair<double,ll>& firstElof, const pair<double,ll>& secondElof){
    return firstElof.second < secondElof.second;
}
#define MAX_N 100100
#define MOD 998244353
// 四方向への移動ベクトル
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
ll gcd(ll a,ll b) {return b ? gcd(b,a%b):a;}
ll lcm(ll c,ll d){return c/gcd(c,d)*d;}

int main(){
    ll n;
    cin >> n;
    vector<ll> a,b,c;
    for (ll i=0;i<n;i++){
        ll m;
        cin >> m;
        a.push_back(m);
    }
    for (ll i=0;i<n;i++){
        ll m;
        cin >> m;
        b.push_back(m);
    }
    for (ll i=0;i<n;i++){
        ll m;
        cin >> m;
        c.push_back(m);
    }
    ll ans=0;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    sort(c.begin(),c.end());
    for (ll i=0;i<n;i++){
        ll p=b[i];
        auto x=lower_bound(c.begin(),c.end(),p+1),y=upper_bound(a.begin(),a.end(),p-1);
        ll X=c.end()-x;
        ll Y=y-a.begin();
        ans+=X*Y;
    }
    cout << ans << endl;
    return 0;
}    
