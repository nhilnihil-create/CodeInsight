#include <bits/stdc++.h>

#define MAX_S 8000

using namespace std;

// a[0], a[1] ,..., a[n-1], s: nonnegative integers.
// sum_i a[i] <= 64*m and s <= 64*m.
// If there exists a subset I of {0, 1,..., n-1} s.t.
// sum_{i in I} a[i] == s,
// return true.
// O(nm)
bool subsetSum(vector<int>::iterator a, int n, int s, int m)
{
    if (s == 0) {
        return true;
    }
    uint64_t *d = new uint64_t[m+1]();
    d[0] = 1ULL << 63;
    for (int i = 0; i < n; i++) {
        int q = a[i] >> 6;
        int r = a[i] & 63;
        for (int j = m - q; j > 0; j--) {
            d[j+q] |= (r == 0 ? 0 : (d[j-1] >> (64-r))) | (d[j] << r);
        }
    }
    int q = 1 + ((s-1) >> 6);
    int r = (s-1) & 63;
    if (d[q] & (1ULL << r)) {
        return true;
    } else {
        return false;
    }
}

bool f(vector<int>::iterator a, int n, int x)
{
    int m = 0;
    for (int i = 0; i < n; i++) {
        m += a[i];
    }
    if (m < x || (m-x) % 2 == 1) {
        return false;
    }
    return subsetSum(a, n, (m-x) / 2, MAX_S / 64);
}

int main(void)
{
    string s;
    int x, y;

    cin >> s;
    cin >> x >> y;
    //cout << "s: " << s << ", size: " << s.size() << endl;

    vector<int> dxs;
    vector<int> dys;

    auto it = s.begin();
    while (*it == 'F') {
        it++;
        x--;
    }
    //cout << "skipped " << it - s.begin() << " leading F's" << endl;
    int direction = 1; // 1: parallel to x axis, -1: parallel to y axis
    int distance = 0;
    for (; it <= s.end(); it++) {
        if (it == s.end() || *it == 'T') {
            if (direction == 1) {
                dxs.push_back(distance);
            } else if (direction == -1) {
                dys.push_back(distance);
            }
            direction *= -1;
            distance = 0;
        } else if (*it == 'F') {
            distance++;
        }
    }

    /*
    cout << "dxs:" << endl;
    for (auto it = dxs.begin(); it < dxs.end(); it++) {
        cout << *it << endl;
    }

    cout << "dys:" << endl;
    for (auto it = dys.begin(); it < dys.end(); it++) {
        cout << *it << endl;
    }
    */

    if (f(dxs.begin(), dxs.size(), x) && f(dys.begin(), dys.size(), y)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
