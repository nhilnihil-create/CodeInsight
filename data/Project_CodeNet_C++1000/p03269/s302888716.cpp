#include <bits/stdc++.h>

using namespace std;

int n = 1, L;
struct edge { int u, v, w; };
vector<edge> res;

int main() {
    cin >> L;
    int tmp = 1;
    while (tmp * 2 <= L) {
        res.push_back({n, n + 1, 0});
        res.push_back({n, n + 1, tmp});
        tmp *= 2; n++;
    }
    while (tmp < L) {
        int id = 1, tmp2 = 1;
        while (tmp2 * 2 < L - tmp)
            id++, tmp2 *= 2;
        res.push_back({id, n, tmp});
        tmp += tmp2;
    }
    cout << n << " " << res.size() << endl;
    for (edge get: res)
        cout << get.u << " " << get.v << " " << get.w << endl;
}
