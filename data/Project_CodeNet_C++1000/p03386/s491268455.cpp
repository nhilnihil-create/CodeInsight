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

int main() {
    int A, B, K;
    cin >> A >> B >> K;
    vb ans(B, false);
    for (int i = 0; i < K; i++) {
        if (A + 1 - 1 < B) {
            ans[A + i - 1] = true;
        }
        if (0 <= B - i - 1) {
            ans[B - i - 1] = true;
        }
    }
    for (int i = A - 1; i < B; i++) {
        if (ans[i]) {
            cout << i + 1 << endl;
        }
    }
}
