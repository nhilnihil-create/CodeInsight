#include <bits/stdc++.h>
// #include <atcoder/all> // NOTE: AtCoderライブラリ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
// using namespace atcoder; // NOTE: AtCoderライブラリ
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef pair<int, int> pii;
// #define INF __INT32_MAX__
#define INF 1e9
#define LINF __LONG_LONG_MAX__

int main() {
    int N, M; cin >> N >> M;
    vector<int> A(M), B(M); rep(i, M) cin >> A[i] >> B[i];
    
    vector<pii> x(M);
    rep(i, M) x[i] = make_pair(A[i], B[i]);

    sort(x.begin(), x.end(), [](const pii &a, const pii &b) {
        return a.second < b.second;
    });

    int prev = -INF;
    int cnt = 0;
    rep(i, M) {
        if (prev <= x[i].first) {
            prev = x[i].second;
            cnt++;
        }
    }

    cout << cnt << endl;
}
