#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define MIN(a) *min_element(all(a))
#define MAX(a) *max_element(all(a))
#define SUM(a) accumulate(all(a), 0LL)
#define REP(i, n) for(int (i)=0; (i)<(n); (i)++)
#define RREP(i, n) for(int (i)=(n)-1; (i)>=0; (i)--)
#define FOR(i, m, n) for(int (i)=(m); (i)<(n); i++)
#define FORR(i, m, n) for(int (i)=(n)-1; (i)>=(m); i--)
#define debug(x) cerr << #x << " = " << x << endl
//#define int long long

typedef long long ll;
//ll const MOD = 998244353;
ll const MOD = 1e9+7;
int const inf = 1e9;
ll const INF = 1e18;

inline void ios_(){cin.tie(0); ios::sync_with_stdio(false);}
template<typename T> int size(const T& a){return (int)a.size();}
template<typename T> T Div(T a, T b){return (a + b - 1) / b;}
template<typename T> bool chmin(T& a, const T& b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, const T& b){if(a < b){a = b; return true;} return false;}

ll BinarySearch(ll ng, ll ok, const function<bool(ll)>& judge){
    while(abs(ok - ng) > 1){
        ll mid = (ok + ng) / 2;
        if(judge(mid)) ok = mid;
        else ng = mid;
    }
    return ok;
}


signed main(){
    ll k;
    cin >> k;
    vector<ll> v(k);
    for(auto&& i : v) cin >> i;

    ll rem = 2;

    auto fn = [&](ll x){
        REP(i, k){
            x -= x % v[i];
            if(x < rem){
                return false;
            }
        }
        return true;
    };

    ll mi = BinarySearch(0, 1e18, fn);
    rem = 3;
    ll ma = BinarySearch(0, 1e18, fn) - 1;

    if(mi > ma){
        cout << -1 << endl;
    }else{
        cout << mi << " " << ma << endl;
    }

    return 0;
}
