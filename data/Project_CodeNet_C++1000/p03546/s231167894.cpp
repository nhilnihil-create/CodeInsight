#include "bits/stdc++.h"

using namespace std;

//// Original version
//int dfs(int curr, const vector<vector<int> >& c, bitset<10> passed) {
//    passed.set(curr);
//    int ret = c[curr][1];
//    for (int i = 0; i < 10; ++i) {
//        if (!passed[i] && i != curr && i != 1) {
//            ret = min(ret, dfs(i, c, passed) + c[curr][i]);
//        }
//    }
//    return ret;
//}
//
//void Main() {
//    int H, W;
//    cin >> H >> W;
//    vector<vector<int> > c(10, vector<int>(10, 0));
//    for (int i = 0; i < 10; ++i) {
//        for (int j = 0; j < 10; ++j) {
//            cin >> c[i][j];
//        }
//    }
//    map<int, int> A;
//    for (int i = 0; i < H; ++i) {
//        for (int j = 0; j < W; ++j) {
//            int a;
//            cin >> a;
//            if (a >= 0) {
//                if (A.count(a) == 0) {
//                    A.insert(make_pair(a, 0));
//                }
//                ++A[a];
//            }
//        }
//    }
//
//    vector<int> power(10, 0);
//    power[1] = 0;
//    for (int i = 0; i <= 9; ++i) {
//        bitset<10> passed(0);
//        power[i] = dfs(i, c, passed);
//    }
//
//    int ans = 0;
//    for (auto e : A) {
//        ans += power[e.first] * e.second;
//    }
//    cout << ans << endl;
//}

// Warshall-Floyd version
void Main() {
    int H, W;
    cin >> H >> W;
    vector<vector<int> > c(10, vector<int>(10, 0));
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            cin >> c[i][j];
        }
    }

    for (int k = 0; k < 10; ++k) {
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < H * W; ++i) {
        int a;
        cin >> a;
        if (a >= 0) {
            ans += c[a][1];
        }
    }
    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
