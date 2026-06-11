#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <stack>
#include <map>
#include <set>

#define REP(i,a) for(int i = 0;i < (a);++i)
#define FOR(i,a,b) for(int i = (a);i < (b); ++i)
#define ALL(obj) (obj).begin(),(obj).end()
#define SIZE(obj) (int)(obj).size()
#define MAX(list) std::max(list)
#define MIN(list) std::min(list)

template<typename T>
T round_up(const T& a, const T& b) {
    return (a + (b - 1)) / b;
}

using ll = long long;
using namespace std;
ll mod = 1'000'000'007;

const int INF = 1'050'000'000;

int main() {
    int N;
    cin >> N;
    vector<int>A(N);
    REP(i, N)cin >> A[i];
    sort(ALL(A));
    int n = A[N - 1];

    auto rIt = lower_bound(ALL(A), n / 2);
    int r1 = *rIt;
    int r2 = *(rIt - 1);

    if (n == r1)cout << n << " " << r2 << endl;
    else if (n == r2)cout << n << " " << r1 << endl;
    else if (r1 - (n / 2) > (n / 2) - r2) {
        cout << n << " " << r2 << endl;
    }
    else {
        cout << n << " " << r1 << endl;
    }
    return 0;
}