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
    long long H;
    cin >> H;

    vector<int> A(n);
    vector<int> B(n);

    for (int i = 0; i < n; ++i) {
        cin >> A[i] >> B[i];
    }

    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(),
        [&](int l, int r) { return B[l] > B[r];});

    vector<int> ord2(n);
    iota(ord2.begin(), ord2.end(), 0);
    sort(ord2.begin(), ord2.end(),
        [&](int l, int r) { return A[l] > A[r];});

    long long res = 1LL << 50;
    long long sum = 0;

    for (int i = 0, j = 0; i < n; ++i) {
        while (j < n && B[ord[j]] >= A[ord2[i]]) {
            sum += B[ord[j]];
            if (sum >= H) {
                res = min(res, j + 1LL);
            }
            ++j;
        }
        long long cnt = j;
        long long rem = max(0LL, H - sum);
        cnt += (rem + A[ord2[i]] - 1) / A[ord2[i]];
        res = min(res, cnt);
    }

    cout << res << '\n';
    
    return 0;
}