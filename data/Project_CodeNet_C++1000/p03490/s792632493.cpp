//subsetSumが間違っているのかと思って簡単なのに書き直したが、
//test1WA.cppと同じテストケースでWA
//mainやbool f()周辺を間違えているのだろうか

#include <bits/stdc++.h>

#define MAX_S 8000

using namespace std;

bool subsetSum(vector<int>::iterator a, int n, int s, int m)
{
    if (s == 0) {
        return true;
    }
    bool *reachable = new bool[MAX_S+1]();
    reachable[0] = true;
    for (int i = 0; i < n; i++) {
        for (int j = MAX_S; j >= 0; j--) {
            if (j >= a[i]) {
                reachable[j] |= reachable[j-a[i]];
            }
        }
    }
    return reachable[s];
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
