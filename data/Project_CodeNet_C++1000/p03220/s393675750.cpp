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

double f(double a, double b) {
    if (a < b) {
        return b - a;
    }
    else {
        return a - b;
    }
}

int main() {
    int N;
    double T, A;
    cin >> N >> T >> A;
    vector<double> data(N);
    for (int i = 0; i < N; i++) {
        cin >> data[i];
    }
    int ans = 0;
    double tans = 1000;
    for (int i = 0; i < N; i++) {
        double th = f(T - data[i] * 0.006, A);
        if (th < tans) {
            ans = i + 1;
            tans = th;
        }
    }
    cout << ans << endl;
}
