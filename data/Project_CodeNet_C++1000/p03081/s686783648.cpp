#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define MIN(a) *min_element(all(a))
#define MAX(a) *max_element(all(a))
#define SUM(a, b) accumulate(all(a), b)
#define REP(i, n) for(int (i)=0; (i)<(n); (i)++)
#define RREP(i, n) for(int (i)=(n)-1; (i)>=0; (i)--)
#define FOR(i, m, n) for(int (i)=(m); (i)<(n); i++)
#define FORR(i, m, n) for(int (i)=(n)-1; (i)>=(m); i--)
#define ios() cin.tie(0), ios::sync_with_stdio(false)
#define debug(x) cerr << #x << " = " << x << endl
//#define int long long

typedef long long ll;
typedef unsigned long long ull;
//ll const MOD = 998244353;
ll const MOD = 1e9+7;
ll const INF = 1e18;

template<typename T> int size(const T& a){return (int)a.size();}
template<typename T> T Div(T a, T b){return (a + b - 1) / b;}
template<typename T> bool chmin(T& a, const T& b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, const T& b){if(a < b){a = b; return true;} return false;}




template<typename T, class Fn> T BinarySearch(T ng, T ok, Fn judge){
    while(abs(ok - ng) > 1){
        T mid = (ok + ng) / 2;
        if(judge(mid)) ok = mid;
        else ng = mid;
    }
    return ok;
}


signed main(){
    int n, q;
    string s;
    cin >> n >> q >> s;

    vector<pair<char,char>> query(q);
    for(auto& i : query) cin >> i.first >> i.second;

    auto left = [n, s, &query](int m){
        if(m < 0) return false;
        else if(m >= n) return true;
        int i = m;
        for(auto e : query){
            if(s[i] == e.first){
                if(e.second == 'L') i--;
                else i++;
            }
            if(i < 0) return false;
            else if(i >= n) return true;
        }
        return true;
    };

    auto right = [n, s, &query](int m){
        if(m >= n) return false;
        else if(m < 0) return true;
        int i = m;
        for(auto e : query){
            if(s[i] == e.first){
                if(e.second == 'L') i--;
                else i++;
            }
            if(i >= n) return false;
            else if(i < 0) return true;
        }
        return true;
    };

    int l = BinarySearch(-1, n, left);
    int r = BinarySearch(n, -1, right);

    cout << max(0, r - l + 1) << endl;

    return 0;
}
