#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;
constexpr int MAXQUERIES = 20;
#define int long long
// "Vacant"

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    int remaining_queries = MAXQUERIES;

    int left, mid, right;
    string left_seat, mid_seat, right_seat;
    left = 0, right = n - 1;

    remaining_queries -= 2;
    cout << left << endl;
    cin >> left_seat;
    cout << right << endl;
    cin >> right_seat;

    if (left_seat == "Vacant" || right_seat == "Vacant") return 0;

    while (remaining_queries > 0) {
        mid = (left + right) / 2;
        remaining_queries--;
        cout << mid << endl;
        cin >> mid_seat;

        if (mid_seat == "Vacant") break;

        if ((mid - left + 1) % 2 == (left_seat != mid_seat)) {
            right = mid;
            right_seat = mid_seat;
        } else {
            left = mid;
            left_seat = mid_seat;
        }
    }

    return 0;
}
