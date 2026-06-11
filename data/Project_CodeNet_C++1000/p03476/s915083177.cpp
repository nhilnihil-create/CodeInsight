#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) REP(i, 0, n)
#define rrep(i, n) for (int i = (int)(n-1); i >= 0; i--)
#define sz(x) int(x.size())
#define bitsz(x) int(__builtin_popcount(x))
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb(x) push_back(x)
#define INF 1e9
#define LINF 1e18
#define mod 1000000007
template<class T> inline bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b) { if (a > b) { a = b; return 1; } return 0; }
template < typename T > inline string toString( const T &a ) { ostringstream oss; oss << a; return oss.str(); };
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
const int di[4] = {1,0,-1,0};
const int dj[4] = {0,1,0,-1};


bool isPrime(int n) { //素数ならtrue
    for (int i=2; i*i<=n; i++) {
        if (n%i == 0) return false;
    }
    return n != 1;
}

int main() {
    int q; cin >> q;
    vector<int> l(q),r(q);
    rep(i,q) cin >> l[i] >> r[i];

    vector<int> sum(100001,0); //sum[i]:iまでの似た数の個数
    for (int i=1; i<=100000; i++) {
        if (i%2==0) {
            sum[i]=sum[i-1];
            continue;
        }
        bool check = isPrime(i)&isPrime((i+1)/2);
        if (check) sum[i]=sum[i-1]+1;
        else sum[i]=sum[i-1];
    }

    rep(i,q) {
        cout << sum[r[i]]-sum[l[i]-1] << endl;
    }

}