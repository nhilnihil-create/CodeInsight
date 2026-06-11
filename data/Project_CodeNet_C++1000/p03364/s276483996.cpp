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
    int N;
    cin >> N;
    vector<string> S(N);
    rep(i, N) cin >> S[i];

    ll ans = 0;
    rep(k, N) {
        bool flag = true;
        // (A, B) = (0, k)
        rep(y, N) {
            rep(x, N) {
                char ct1 = S[y][x];
                int tox = (y + k) % N, toy = x;
                toy -= k;
                if (toy < 0) toy += N;
                char ct2 = S[toy][tox];
                if (ct1 != ct2) flag = false;
            }
        }
        if (flag) ans += N;
    }

    cout << ans << endl;
    return 0;
}