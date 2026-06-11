#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<stack>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<bitset>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
#define FOR(i,a,n) for(int (i)=(a);(i)<(n);(i)++)
#define eFOR(i,a,n) for(int (i)=(a);(i)<=(n);(i)++)
#define SORT(i) sort((i).begin(),(i).end())
#define rSORT(i,a) sort((i).begin(),(i).end(),(a))
constexpr auto INF = 1000000000;
constexpr auto LLINF = 1LL << 62;
constexpr auto mod = 1000000007;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; }return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; }return 0; }

ll p(ll a,ll n) {
    if (n <= 0)return 1;
    return a * p(a - 1, n - 1) % mod;
}
ll kaijo(ll a) {
    if (a <= 0)return 1;
    return a * kaijo(a - 1) % mod;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<ll> a(n);
    double ave = 0;
    FOR(i, 0, n) {
        cin >> a[i];
        ave += a[i];
    }
    ave /= n;

    int ans = -1;
    double m = INF;
    FOR(i, 0, n)if (chmin(m, abs(a[i] - ave))) {
        ans = i;
    }
    cout << ans << "\n";
}