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

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> wr(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        x--;
        wr[x] = i;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int r = i;
        while (r + 1 < n && wr[r] < wr[r + 1]) {
            r++;
        }
        ans = max(ans, r - i + 1);
        i = r;
    }
    cout << n - ans << endl;
}   