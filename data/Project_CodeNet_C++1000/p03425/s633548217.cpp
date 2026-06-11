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
#include <bitset> // bitset
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vb = vector<bool>;
using vll = vector<long long>;
using pii = pair<int, int>;
using psi = pair<string, int>;

int main() {
    int N;
    cin >> N;
    vector<string> data(N, " ");
    for (int i = 0; i < N; i++) {
        cin >> data[i];
    }
    vll march(5, 0);
    for (string s : data) {
        if (s[0] == 'M') {
            march[0]++;
        }
        else if (s[0] == 'A') {
            march[1]++;
        }
        else if (s[0] == 'R') {
            march[2]++;
        }
        else if (s[0] == 'C') {
            march[3]++;
        }
        else if (s[0] == 'H') {
            march[4]++;
        }
    }
    ll ans = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 4; j++) {
            for (int k = j + 1; k < 5; k++) {
                ans += march[i] * march[j] * march[k];
            }
        }
    }
    cout << ans << endl;
}
