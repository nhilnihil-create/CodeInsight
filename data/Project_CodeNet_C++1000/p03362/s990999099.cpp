#include <bits/stdc++.h>
#define REP(i, m, n) for(int (i) = (m); (i) < (n); ++i)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
using namespace std;
using Graph = vector<vector<int>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
typedef long long ll;
typedef pair<ll, ll> P;
const int INF = 1e9+7;
const ll LINF = 1LL<<60;

const int maxa = 55555;

vector<int> prime_val(int n) {
    vector<int> res(n);
    int k = 0;
    for (int i = 2; i <= maxa; ++i) {
        bool ok = true;
        for (int j = 2; j * j <= i; ++j) {
            if (i % j == 0) {
                ok = false;
                break;
            }
        }
        if (ok && i % 5 == 1) {
            res[k] = i;
            ++k;
        }
        if (k == n) {
            return res;
            break;
        }
    }
    return res;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;

    vector<int> res = prime_val(n);

    rep(i, n) {
        cout << res[i];
        if (i != n-1) cout << " ";
    }
    cout << endl;

    return 0;
}