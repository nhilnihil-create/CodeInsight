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
using namespace std;
using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using vll = vector<long long>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<long long>>;
using pii = pair<int, int>;
using psi = pair<string, int>;

int main() {
    vi data(5);
    for (int i = 0; i < 5; i++) {
        cin >> data.at(i);
    }
    int last = 0;
    for (int i = 1; i < 5; i++) {
        if ((data.at(i) - 1) % 10 < (data.at(last) - 1) % 10) {
            last = i;
        }
    }
    int ans = 0;
    for (int i = 0; i < 5; i++) {
        if (i == last || data.at(i) % 10 == 0) {
            ans += data.at(i);
        }
        else {
            ans += data.at(i) - (data.at(i) % 10) + 10;
        }
    }
    cout << ans << endl;
}