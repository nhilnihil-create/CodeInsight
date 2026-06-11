#include <algorithm>
#include <bitset>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <tuple>
#include <vector>

using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define reps(i, f, n) for (ll i = (f); i < (n); i++)
#define repv(v) for (auto it = (v).begin(); it != (v).end(); it++)
ll const INF = 1LL << 60;
ll const MAX_N = 510000;
ll const MOD = 1000000007;

bool check_seats(vector<ll> &v, ll idx, string s) {
    if (s == "Male") {
        v[idx] = 1;
        return false;
    } else if (s == "Female") {
        v[idx] = -1;
        return false;
    }

    return true;
}

int main() {
    ll N;
    cin >> N;
    vector<ll> seats(N);

    string ans;
    cout << 0 << endl;
    cin >> ans;

    if (check_seats(seats, 0, ans)) return 0;

    cout << N - 1 << endl;
    cin >> ans;
    if (check_seats(seats, N - 1, ans)) return 0;

    bool is_end = false;
    ll l = 0, r = N - 1;
    ll mid;
    while (!is_end) {
        mid = (l + r) / 2;
        cout << mid << endl;
        cin >> ans;
        is_end = check_seats(seats, mid, ans);
        if ((mid - l) % 2 == 1 && seats[l] * seats[mid] > 0 ||
            (mid - l) % 2 == 0 && seats[l] * seats[mid] < 0) {
            r = mid;
        } else
            l = mid;
    }
    return 0;
}
