#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;

int main() {
    int N; cin >> N;
    vector<int> t(N + 1), v(N + 2);
    for (int i = 1; i <= N; i++) {cin >> t[i]; t[i] *= 2;} // 全部スケール 2 倍にしておく
    for (int i = 1; i <= N; i++) {cin >> v[i]; v[i] *= 2;}

    vector<int> l(N + 2), r(N + 2);
    l[0] = r[0] = 0; v[0] = 0;
    for (int i = 1; i <= N; i++) {
        l[i] = r[i - 1];
        r[i] = l[i] + t[i];
    }
    l[N + 1] = r[N + 1] = r[N]; v[N + 1] = 0;

    int T = r[N + 1];
    vector<int> min_v(T + 1, INF);
    for (int i = 0; i <= N + 1; i++) {
        for (int j = 0; j <= T; j++) {
            if (j < l[i]) min_v[j] = min(min_v[j], v[i] + l[i] - j);
            else if (r[i] < j) min_v[j]= min(min_v[j], v[i] + j - r[i]);
            else min_v[j] = min(min_v[j], v[i]);
        }
    }

    double ans = 0;
    for (int i = 1; i <= T; i++) {
        ans += ((double)min_v[i - 1] + (double)min_v[i])/2.0;
    }

    cout << fixed << ans/4.0 << endl;
    return 0;
}