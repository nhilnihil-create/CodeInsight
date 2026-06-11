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

const int INF = 1e9;
const long long LINF = 1e18;
const double PI=3.14159265358979323846;

int gcd(int a, int b) {
    if (a < b) {
        swap(a, b);
    }
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int ans = A[0];
    for (int i = 1; i < N; i++) {
        ans = gcd(ans, A[i]);
    }

    cout << ans << endl;

    return 0;
}
