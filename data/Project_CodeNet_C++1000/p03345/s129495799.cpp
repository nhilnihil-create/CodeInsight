#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <math.h> // sqrt
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <iomanip> // setprecision
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vb = vector<bool>;
using vll = vector<long long>;
using pii = pair<int, int>;
using psi = pair<string, int>;

ll minusn(ll n) {
    if (n % 2 == 0) {
        return 1;
    }
    return -1;
}

int main() {
    ll A, B, C, K;
    cin >> A >> B >> C >> K;
    if (K == 0) {
        cout << A - B << endl;
        return 0;
    }
    if (K == 1) {
        cout << B - A << endl;
        return 0;
    }
    if (A == B && B == C) {
        cout << 0 << endl;
        return 0;
    }
    ll i, j;
    i = 2 * minusn(K - 2);
    j = minusn(K - 1);
    ll ans = i * (A - B) + j * (B - A);
    cout << ans / 3 << endl;
}