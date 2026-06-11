#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
typedef unsigned long ul;
typedef pair<ul, ul> P;

int main() {
    int n;
    int t[110000], x[110000], y[110000];

    t[0] = x[0] = y[0] = 0;

    cin >> n;
    for(int i = 1; i < n + 1; i++) {
        cin >> t[i] >> x[i] >> y[i];
    }

    bool can = true;
    // t[i]秒で(x[i],y[i])に移動できるか調べていく
    for(int i = 1; i < n + 1; i++) {
        int dt = t[i] - t[i - 1];
        int dist = abs(x[i] - x[i - 1]) + abs(y[i] - y[i - 1]);
        if(dt < dist)
            can = false;
        if(dist % 2 != dt % 2)
            can = false;
    }

    if(can)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}