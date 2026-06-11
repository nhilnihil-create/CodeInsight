#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <utility>
#include <vector>
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; ++i)
#define reps(i, n) for(int i = 1, i##_len = (n); i <= i##_len; ++i)
#define rrep(i, n) for(int i = ((int)(n)-1); i >= 0; --i)
#define rreps(i, n) for(int i = ((int)(n)); i > 0; --i)
#define INF 100000000

using namespace std;

int n, A, B, C;
vector<int> l;

void chmin(int &a, int b) {
    if(a > b)
        a = b;
}

int dfs(int i, int a, int b, int c) {
    if(i == n) {
        if(a == 0 || b == 0 || c == 0)
            return INF;
        return abs(A - a) + abs(B - b) + abs(C - c);
    }

    int res = INF;

    chmin(res, dfs(i + 1, a, b, c));
    chmin(res, dfs(i + 1, a + l[i], b, c) + (a ? 10 : 0));
    chmin(res, dfs(i + 1, a, b + l[i], c) + (b ? 10 : 0));
    chmin(res, dfs(i + 1, a, b, c + l[i]) + (c ? 10 : 0));

    return res;
}

int main() {
    cin >> n >> A >> B >> C;
    l.resize(n);
    for(int i = 0; i < n; i++)
        cin >> l[i];
    int res = dfs(0, 0, 0, 0);
    cout << res << endl;
    return 0;
}