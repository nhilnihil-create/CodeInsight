#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
#define INF 200000
#define ALL(v) v.begin(), v.end()
#define vmax(v) *max_element(ALL(v))
#define vmin(v) *min_element(ALL(v))
#define chmax(x, a) x = max(x, a)
#define chmin(x, a) x = min(x, a)

int main() {
    int N, M; cin >> N >> M;
    vector<int> check(N, INF);
    int a, b;
    rep(i, M) {
        cin >> a >> b;
        a--; b--;
        chmin(check[min(a, b)], max(a, b));
    }
    int tmp = check[0], cnt = 0;
    rep2(i, 1, N) {
        if (tmp == i) {
            cnt++;
            tmp = check[i];
        }
        else if (tmp > check[i]) {
            tmp = check[i];
        }
    }
    cout << cnt << endl;
}
