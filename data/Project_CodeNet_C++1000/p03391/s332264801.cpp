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
        cin >> A[i] >> B[i];
    }

    if (A == B) {
        cout << 0 << '\n';
        return 0;
    }

    long long res = accumulate(A.begin(), A.end(), 0LL);
    int mn = 1 << 30;
    for (int i = 0; i < n; ++i) {
        if (A[i] > B[i]) {
            mn = min(mn, B[i]);
        }
    }
    res -= mn;

    cout << res << '\n';


    return 0;
}