#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<stack>
#include<cmath>
#include<iomanip>
#include<set>
#include<numeric>
#include<sstream>
#include<random>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rrep(i, st, n) for (int i = st; i < n; ++i)
using pii = pair<int, int>;
const int inf = 1e9 + 7;
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int dx[] = {1, -1, 0, 0, -1, 1, 1, -1};

random_device rnd;
mt19937 mt(rnd());
uniform_int_distribution<> rand100(1, 100);
uniform_int_distribution<> rand200(1, 200);

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    /*
    int n; n = rand100(mt); cout << n << endl;
    int sum = 0;
    int t[n]; rep(i, n) {t[i] = rand200(mt); sum += t[i]; cout << t[i] << " ";} cout << endl;
    int v[n]; rep(i, n) {v[i] = rand100(mt); cout << v[i] << " ";} cout << endl;
     */
    int n; cin >> n;
    int sum = 0;
    int t[n]; rep(i, n) {cin >> t[i]; sum += t[i];}
    int v[n]; rep(i, n) cin >> v[i];
    double maxv[2 * sum + 1];
    int now = 1;
    rep(i, n) {
        rep(j, 2 * t[i]) {
            maxv[now + j] = v[i];
        }
        now += 2 * t[i];
    }
    now = 0;
    rep(i, n - 1) {
        maxv[now + 2 * t[i]] = min(v[i], v[i + 1]);
        now += 2 * t[i];
    }
    maxv[0] = maxv[2 * sum] = 0;
    //rep(i, 2 * sum + 1) cout << i << " " << maxv[i] << endl;
    rrep(i, 1, 2 * sum + 1) { //上がりの条件
        maxv[i] = min(maxv[i], maxv[i - 1] + 0.5);
    }
    for (int i = 2 * sum - 1; i >= 0; --i) { //下がりの条件
        maxv[i] = min(maxv[i], maxv[i + 1] + 0.5);
    }
    //rep(i, 2 * sum + 1) cout << i << " " << maxv[i] << endl;
    double s = 0;
    cout << fixed << setprecision(5);
    rrep(i, 1, 2 * sum + 1) {
        s += (maxv[i] + maxv[i - 1]) * 0.25;
    }
    cout << s << endl;
}

