#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

const ll INF = 1145141919810364364;

vector<ll> calc(vector<ll> &c_sum, int mi, int ma) {
    int ok = ma, ng = mi;
    while (ok - ng > 1) {
        int mid = (ok + ng) / 2;

        if (c_sum[ma] - c_sum[mid] <= c_sum[mid] - c_sum[mi])ok = mid;
        else ng = mid;
    }

    ll p = c_sum[ma] - c_sum[ok], q = c_sum[ok] - c_sum[mi]; // p <= q
    ll r = c_sum[ma] - c_sum[ng], s = c_sum[ng] - c_sum[mi]; // r > s
    return {p, q, r, s};
}

int main() {
    int n;
    cin >> n;
    vector<ll> c_sum(n + 1);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        c_sum[i + 1] = a + c_sum[i];
    }

    ll ret = INF;
    for (int i = 2; i <= n - 2; i++) { // [0, i) [i,n)
        auto front = calc(c_sum, 0, i), back = calc(c_sum, i, n);
        ret = min(ret, max(front[1], back[1]) - min(front[0], back[0]));
        ret = min(ret, max(front[1], back[2]) - min(front[0], back[3]));
        ret = min(ret, max(front[2], back[1]) - min(front[3], back[0]));
        ret = min(ret, max(front[2], back[2]) - min(front[3], back[3]));
    }

    cout << ret << endl;
    return 0;
}