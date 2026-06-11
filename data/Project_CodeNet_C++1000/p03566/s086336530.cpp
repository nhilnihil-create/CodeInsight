#include <iostream>
#include <algorithm>
#include <complex>
#include <utility>
#include <vector>
#include <string>
#include <queue>
#include <tuple>
#include <cmath>
#include <bitset>
#include <cctype>
#include <set>
#include <map>
#include <numeric>
#include <functional>
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(ll i=ll(a);i<ll(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()
#define PRINT(V) cout << V << "\n"
#define SORT(V) sort((V).begin(),(V).end())
#define RSORT(V) sort((V).rbegin(), (V).rend())
using namespace std;
using ll = long long;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
inline void Yes(bool condition){ if(condition) PRINT("Yes"); else PRINT("No"); }
template<class itr> void cins(itr first,itr last){
    for (auto i = first;i != last;i++){
        cin >> (*i);
    }
}
template<class itr> void array_output(itr start,itr goal){
    string ans = "",k = " ";
    for (auto i = start;i != goal;i++) ans += to_string(*i)+k;
    if (!ans.empty()) ans.pop_back();
    PRINT(ans);
}
ll gcd(ll a, ll b) {
    return a ? gcd(b%a,a) : b;
}
const int INF = 1e9;
const ll MOD = 1000000007;
typedef pair<ll,ll> P;
const ll MAX = 20000;
constexpr ll nx[4] = {1,0,-1,0};
constexpr ll ny[4] = {0,1,0,-1};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<ll> t(n),v(n);
    cins(all(t));
    cins(all(v));
    vector<vector<double>> dp(40005,vector<double>(205,0));
    int now = 0;
    rep(i,n){
        rep(j,1,2*t[i]+1){
            int limit = 2*v[i];
            rep(k,201){
                if ((i != 0 || k != 0) && dp[now+j-1][k] == 0.0) continue;
                if (i != 0 && j == 1){
                    if (k > limit) continue;
                }
                if (k == 0){
                    dp[now+j][0] = dp[now+j-1][0];
                    if (1 <= limit) dp[now+j][1] = dp[now+j-1][0]+0.125;
                }
                else if(k == 200){
                    if (200 <= limit) chmax(dp[now+j][200],dp[now+j-1][200]+50);
                    if (199 <= limit) chmax(dp[now+j][199],dp[now+j-1][200]+(2*k-1)/8.0);
                }
                else{
                    if (k-1 <= limit) chmax(dp[now+j][k-1],dp[now+j-1][k]+(2*k-1)/8.0);
                    if (k <= limit) chmax(dp[now+j][k],dp[now+j-1][k]+k/4.0);
                    if (k+1 <= limit) chmax(dp[now+j][k+1],dp[now+j-1][k]+(2*k+1)/8.0);
                }
            }
        }
        now += 2*t[i];
    }
    printf("%0.10f\n",dp[now][0]);
}
