#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)

int main() {
    vector<int> a(3); REP(i, 3) cin >> a[i];
    sort(a.begin(), a.end());

    if (a[1] % 2 == a[0] % 2)
        cout << (a[1] - a[0]) / 2 - a[1] + a[2] << endl;
    else
        cout << (a[1] - a[0] + 1) / 2 - a[1] + a[2] + 1 << endl;

    return 0;
}