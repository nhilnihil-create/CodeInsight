#include <algorithm>
#include <cassert>
#include <climits>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;

const int INF = 1e9;
const long long LINF = 1e18;
const double PI=3.14159265358979323846;

typedef priority_queue<int, vector<int>, greater<int>> priority_queue_asc;

vector<int> h;

int solve(int l, int r) {
    // cout << "(l, r) = " << l << ", " << r << endl;
    // for (int i = l; i < r; i++) {
        // cout << h[i] << ' ';
    // }
    // cout << endl;
    if (l == r) {
        return 0;
    }
    int minh = INF;
    for (int i = l; i < r; i++) {
        minh = min(h[i], minh);
    }
    for (int i = l; i < r; i++) {
        h[i] -= minh;
    }

    // cout << "minh: " << minh << endl;

    int ans = minh;
    int nl = 0, nr;
    for (int i = l; i < r; i++) {
        if (h[i] == 0) {
            nr = i;
            ans += solve(nl, nr);
            nl = nr + 1;
        }
    }
    ans += solve(nl, r);
    return ans;
}

int main() {
    int N;
    cin >> N;

    h.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> h[i];
    }


    cout << solve(0, N) << endl;

    return 0;
}
