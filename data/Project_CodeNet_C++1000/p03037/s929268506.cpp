#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#define ll long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    int curr_range_s = 1;
    int curr_range_e = n;
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        curr_range_s = max(curr_range_s, l);
        curr_range_e = min(curr_range_e, r);
    }
    cout << max(0, curr_range_e - curr_range_s + 1);
}