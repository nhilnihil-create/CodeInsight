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
    string S;
    cin >> S;
    int ans0 = 0, ans1 = 0;
    for (int i = 0; i < S.size(); i++) {
        if (i % 2 == 0) {
            if (S.at(i) == '0') {
                ans1++;
            }
            else {
                ans0++;
            }
            continue;
        }
        if (S.at(i) == '0') {
            ans0++;
        }
        else {
            ans1++;
        }
    }
    int ans = min(ans0, ans1);
    cout << ans << endl;
}