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
    vector<int> A(N);
    vector<double> sum(N + 1);
    rep(i, N) {
        cin >> A[i];
        sum[i + 1] = A[i] + sum[i];
    }

    ll ans = INF;
    repd(i, 1, N - 2) {
        double l = sum[i + 1], r = sum[N] - sum[i + 1];
        int indexl = upper_bound(all(sum), l / 2.0) - sum.begin();
        ll l1 = INF, l2 = INF;
        if (indexl - 1 > 0) {
            l1 = abs(sum[indexl - 1] - (sum[i + 1] - sum[indexl - 1]));
        }
        if (indexl <= i) {
            l2 = abs(sum[indexl] - (sum[i + 1] - sum[indexl]));
        }
        int indexr = upper_bound(all(sum), l + (r / 2.0)) - sum.begin();
        ll r1 = INF, r2 = INF;
        if (indexr - 1 > i + 1) {
            r1 = abs((sum[indexr - 1] - sum[i + 1]) - (sum[N] - sum[indexr - 1]));
        }
        if (indexr <= N) {
            r2 = abs((sum[indexr] - sum[i + 1]) - (sum[N] - sum[indexr]));
        }
        vector<ll> res(4);
        if (l1 < l2) {
            res[0] = sum[indexl - 1];
            res[1] = sum[i + 1] - sum[indexl - 1];
        }
        else {
            res[0] = sum[indexl];
            res[1] = sum[i + 1] - sum[indexl];
        }
        if (r1 < r2) {
            res[2] = sum[indexr - 1] - sum[i + 1];
            res[3] = sum[N] - sum[indexr - 1];
        }
        else {
            res[2] = sum[indexr] - sum[i + 1];
            res[3] = sum[N] - sum[indexr];
        }
        sort(all(res));
        chmin(ans, res[3] - res[0]);
    }

    cout << ans << endl;
    return 0;
}