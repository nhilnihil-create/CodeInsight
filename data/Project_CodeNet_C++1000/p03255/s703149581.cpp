#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>
#include <random>

using namespace std;

#define int long long

const int INF = 100000000000000239;

int safe_mul(int a, int b) {
    a = min(a, INF);
    b = min(b, INF);
    if (a >= (INF) / b) return INF;
    else return min(INF, a * b);
}
 
int safe_add(int a, int b) {
    a = min(a, INF);
    b = min(b, INF);
    return min(INF, a + b);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    int n, add;
    cin >> n >> add;
    vector<int> a(n);
    for (auto &t : a) {
        cin >> t;
    }
    reverse(a.begin(), a.end());
    vector<int> psum(n + 1);
    for (int i = 0; i < n; i++) {
        psum[i + 1] = a[i] + psum[i];
    }
    int ans = INF;
    for (int cnt = 1; cnt <= n; cnt++) {
        int lol = (n + cnt) * add;
        int grlen = cnt;
        int pnt = 0;
        int num = 0;
        for (; pnt < n; num++) {
            int rl = (grlen);
            int val = (3 + 2 * (num));
            if (!num) val += 2;
            int sm = psum[min(n, pnt + rl)] - psum[pnt];
            lol = safe_add(lol, safe_mul(val, sm));
            pnt += rl;
        }
        ans = min(ans, lol);
    }
    cout << ans << endl;
}   
