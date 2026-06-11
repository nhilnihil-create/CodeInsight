#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const long long INF = 1LL << 60;
typedef pair<int, int> P;
int main()
{
    ll N;
    cin >> N;

    for (ll h = 1; h <= 3500; h++) {
        for (ll n = 1; n <= 3500; n++) {
            ll a = N * h * n;
            ll b = 4 * h * n - N * n - N * h;
            if (b <= 0 || a % b != 0) continue;
            cout << h << " " << n << " " << a / b << endl;
            return 0;
        }
    }
    return 0;
}