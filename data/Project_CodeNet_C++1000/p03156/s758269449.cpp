#include<bits/stdc++.h>
#include<cmath>
#pragma GCC optimize("Ofast")
using namespace std;
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
typedef long long ll;
const ll MOD = 1000000007;
#define rep(i,n) for(ll i=0, i##_len=(n); i<i##_len; ++i)
#define REP(i,num,n) for(ll i=num, i##_len=(n); i<i##_len; ++i)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
template<class T> inline void add(T &a, T b){a = ((a+b) % MOD + MOD) % MOD;};
#define print(x) cout << (x) << endl;
#define pb push_back
#define mp make_pair
#define sz(x) int(x.size())
 
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
const int INF = 1e9;
const ll LLINF = 1e16;
 
template<typename T>
vector<T> make_v(size_t a){return vector<T>(a);}
 
template<typename T,typename... Ts>
auto make_v(size_t a,Ts... ts){
  return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));
}
 
template<typename T,typename U,typename... V>
typename enable_if<is_same<T, U>::value!=0>::type
fill_v(U &u,const V... v){u=U(v...);}
 
template<typename T,typename U,typename... V>
typename enable_if<is_same<T, U>::value==0>::type
fill_v(U &u,const V... v){
  for(auto &e:u) fill_v<T>(e,v...);
}
 
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};
 
ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}

using pint = pair<int, int>;
using pll = pair<ll, ll>;

int main(void)
{
    cout.tie(0);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    ll n;
    cin >> n;
    ll a,b;
    cin >> a >> b;
    vector<ll> p(n);
    rep(i,n) cin >> p[i];
    ll min1 = 0;
    ll min2 = 0;
    ll min3 = 0;
    rep(i,n){
      if(p[i] <= a) min1++;
      if(a+1 <= p[i] && p[i] <= b) min2++;
      if(p[i] >= b+1) min3++;
    }
    print(min({min1,min2,min3}));
}