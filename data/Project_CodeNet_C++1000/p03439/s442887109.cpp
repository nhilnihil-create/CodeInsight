#include <bits/stdc++.h>
using namespace std;
int quelim = 20;
bool query(int k) {
    if (quelim-- <= 0) exit(0);
    string s;
    cout << k << endl;
    cin >> s;
    if (s == "Vacant") exit(0);
    if (s == "Male") return false;
    if (s == "Female") return true;
}
int main() {
    int n;
    cin >> n;
    vector<int> seat(n, -1);
    int l = 0, r = n - 1;
    seat[0] = query(0);
    while (r - l + 1 > quelim && l + 1 < r) {
        bool a, b;
        int m = (l + r) / 2, lsiz = m - l + 1;
        a = (seat[l]);
        if (seat[m] < 0) seat[m] = query(m);
        b = (seat[m]);
        if (((lsiz & 1) && a == b) || (!(lsiz & 1) && a != b))
            l = m;
        else
            r = m;
    }
    for (int i = l; i <= r; ++i) {
        if (seat[i] < 0) seat[i] = query(i);
    }
    return 0;
}