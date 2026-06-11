#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <cstring>
#include <queue>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <cstdlib>
#include <sstream>
#include <bitset>

using namespace std;

using ll = long long;
using Vec = vector<ll>;
using P = pair<ll, ll>;
using VecP = vector<P>;
#define rep(i, n) for(ll i=0;i<(n);i++)
#define SIZE_OF_ARRAY(array) (sizeof(array)/sizeof(array[0]))

//static const ll MOD = 1000000007;
//static const ll INF = 100000000;
//#define PI 3.14159265359


int main() {
    // input
    ll N;
    cin >> N;
    Vec a(N, 0), b(N, 0);
    ll sum_a = 0, sum_b = 0;
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
        sum_a += a[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> b[i];
        sum_b += b[i];
    }

    // process
    ll count = 0;
    rep(i, N) {
        if (a[i] < b[i]) {
            count += ceil(((double) b[i] - (double) a[i]) / 2.0);
        }
    }

    if (count > sum_b - sum_a) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }

    return 0;
}

