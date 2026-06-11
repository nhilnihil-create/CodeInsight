#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    map<int, int> d;
    for (int i=0; i<n; ++i) {
        int num; cin >> num;
        d[num]++;
    }
    bool can = true;
    int m; cin >> m;
    for (int i=0; i<m; ++i) {
        int num; cin >> num;
        d[num]--;
        if (d[num] < 0) can = false;
    }
    cout << (can ? "YES" : "NO") << endl;
}