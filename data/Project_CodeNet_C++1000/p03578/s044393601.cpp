#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, dd;
    cin >> n;
    map<int, int> d;
    for (int i = 0; i < n; i++) {
        cin >> dd;
        d[dd]++;
    }
    int m, t;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> t;
        if (d[t] > 0) d[t]--;
        else {
            cout << "NO" << endl;
            return 0;
        } 
    }
    cout << "YES" << endl;
}