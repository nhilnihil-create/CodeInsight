#include <iostream>
#include <iomanip>
#include <algorithm>
#include <complex>
#include <utility>
#include <vector>
#include <string>
#include <stack>
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
const ll INF = 1e15;
const ll MOD = 100000000;
const ll MOD2 = 998244353;
typedef pair<ll,ll> P;
const ll MAX = 200010;
constexpr ll nx[8] = {1,0,-1,0,-1,-1,1,1};
constexpr ll ny[8] = {0,1,0,-1,-1,1,-1,1};
vector<vector<ll>> ans;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll h,w;
    cin >> h >> w;
    vector<vector<ll>> a(h,vector<ll>(w));
    rep(i,h){
        rep(j,w){
            cin >> a[i][j];
        }
    }
    int flag = 0;
    int x = 0,y = 0,cnt = 1;
    while(cnt < h*w){
        int nx = x,ny = y;
        if (x%2 == 0){
            if (y < w-1) ny = y+1;
            else nx = x+1;
        }
        else{
            if (y > 0) ny = y-1;
            else nx = x+1;
        }
        if (a[x][y]%2){
            flag = 1-flag;
        }
        if (flag){
            ans.push_back(vector<ll>{x+1,y+1,nx+1,ny+1});
        }
        x = nx;
        y = ny;
        cnt++;
    }
    PRINT(ans.size());
    rep(i,ans.size()) array_output(all(ans[i]));
}
