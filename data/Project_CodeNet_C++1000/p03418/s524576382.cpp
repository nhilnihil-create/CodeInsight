#include <bits/stdc++.h>
using namespace std;

#define repd(i,a,b) for (ll i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;

const long long INF = 1LL << 60;

int main()
{
    ll N, K;
    cin >> N >> K;

    ll ans = 0;
    repd(i, K + 1, N + 1) {
        ll a, b;
        a = N / i;
        b = N % i;
        ans += a * (i - K);
        ans += max(0LL, b - (K - 1));
    }

    if (K == 0) ans = N * N;
    cout << ans << endl;
    return 0;
}