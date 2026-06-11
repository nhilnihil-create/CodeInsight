// 　　＿＿
// 　／　<＠ﾌ
//  ｜(ﾉﾉハ))
//  ﾉ从ﾟヮﾟ从
// 　ﾉ｜ｿﾉГ|つ author:hotarunx
// 〈_ﾉ^^^ヽ|
// 　~~tｧtｧ~
#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;
#define int long long
constexpr int N = 4;

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    array<int, N> x, y;
    cin >> x[0] >> y[0] >> x[1] >> y[1];

    const int ax = x[1] - x[0];
    const int ay = y[1] - y[0];

    x[2] = x[1] - ay;
    y[2] = y[1] + ax;

    x[3] = x[2] - ax;
    y[3] = y[2] - ay;

    cout << x[2] << " " << y[2] << " " << x[3] << " " << y[3] << endl;
}
