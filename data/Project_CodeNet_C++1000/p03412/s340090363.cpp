#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <bitset>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <string>
#include <chrono>
#include <random>
#include <cmath>
#include <cassert>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <functional>
#include <sstream>

using namespace std;


int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> A(n);
    vector<int> B(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    for (int j = 0; j < n; ++j) {
        cin >> B[j];
    }

    int MX = *max_element(A.begin(), A.end());
    MX = max(MX, *max_element(B.begin(), B.end()));

    int res = 0;
    int h = 0;
    while (1 << (h + 1) <= MX) {
        ++h;
    }
    ++h;

    auto calc = [&](int M) {
        vector<int> SA;
        SA.reserve(n);
        vector<int> SB;
        SB.reserve(n);
        for (int i = 0; i < n; ++i) {
            SA.push_back(A[i] & ((M << 1) - 1));
            SB.push_back(B[i] & ((M << 1) - 1));
        }
        sort(SA.begin(), SA.end());
        sort(SB.begin(), SB.end());

        // for (auto x : SA) {
        //     cout << x << " ";
        // }
        // cout << endl;
        // for (auto x : SB) {
        //     cout << x << " ";
        // }
        // cout << endl;

        long long res = 0;
        for (auto& p : vector<pair<int,int>> {{M, (M << 1) - 1}, {3 * M, (M << 2) - 1}}) {
            int L = p.first;
            int R = p.second;

            for (int i = 0, l = n - 1, r = n - 1; i < n; ++i) {
                while (l >= 0 && SA[i] + SB[l] >= L) {
                    --l;
                }
                while (r >= 0 && SA[i] + SB[r] > R) {
                    --r;
                }
                res += max(0, r - l);
                // cout << M << " " << L << " " << R << " :: " << SA[i] <<  " " << l << " " << r << endl;
            }
        }
        // cout << "res " << res << endl;
        return res;
    };

    for (int i = 0; i <= h; ++i) {
        long long cnt = calc(1 << i);
        if (cnt & 1) {
            res |= 1 << i;
        }
    }

    cout << res << '\n';
    return 0;
}