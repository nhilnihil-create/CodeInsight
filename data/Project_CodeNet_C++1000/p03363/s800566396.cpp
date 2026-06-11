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
    ll N;
    cin >> N;
    vll data(N);
    for (int i = 0; i < N; i++) {
        cin >> data.at(i);
    }
    vll rsum(N + 1, 0);
    ll sum = 0;
    for (int i = 0; i < N; i++) {
        sum += data.at(i);
        rsum.at(i + 1) = sum;
    }
    sort(rsum.begin(), rsum.end());
    ll ans = 0;
    for (ll i = 0; i < N + 1; i++) {
        ll count = 1;
        while (true) {
            if (N + 1 <= i + count) {
                break;
            }
            if (rsum.at(i) == rsum.at(i + count)) {
                count++;
            }
            else {
                break;
            }
        }
        if (count == 1) {
            continue;
        }
        ans += count * (count - 1) / 2;
        i+= count - 1;
    }
    cout << ans << endl;
}