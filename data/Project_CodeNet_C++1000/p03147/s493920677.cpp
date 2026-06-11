#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using ll = long long;
#define rep(inc, bgn, end) for (int inc = bgn; inc < end; ++inc)
#define repe(inc, bgn, end) for (int inc = bgn; inc <= end; ++inc)

using namespace std;

int func(vector<int> vec, int prevval) {
    if (vec.size() == 0) {
        return 0;
    }

    int minval = vec[0];
    int minidx = 0;
    rep(i, 1, vec.size()) {
        if (vec[i] < minval) {
            minval = vec[i];
            minidx = i;
        }
    }
    vector<int> left;
    vector<int> right;
    rep(i, 0, minidx) {
        left.push_back(vec[i]);
    }
    rep(i, minidx + 1, vec.size()) {
        right.push_back(vec[i]);
    }

    return func(left, minval) + func(right, minval) + (minval - prevval);
}

#define PI 3.141592
// 117 -c
int main() {
    int n;
    cin >> n;

    vector<int> height(n);
    rep(i, 0, n) {
        cin >> height[i];
    }

    // queue<vector<int>> que;
    // que.push(height);
    // while (!que.empty()) {
    //     vector<int> vec = que.front();
    //     que.pop();

    //     // detect min
    //     int minval = vec[0];
    //     rep(i, 1, vec.size()) {
    //         minval = min(minv, vec[i]);
    //     }

    //     // split by minval
    //     int bgn = 0;
    //     vector<int> tmp;
    //     rep(i, bgn, vec.size()) {
    //         if (vec[i] == minval) {
    //             if (tmp.size() != 0) {
    //                 que.push(tmp);
    //                 tmp.clear();
    //             }
    //         }
    //         else{
    //             vec
    //     }
    // }

    cout << func(height, 0) << endl;

    return 0;
}
