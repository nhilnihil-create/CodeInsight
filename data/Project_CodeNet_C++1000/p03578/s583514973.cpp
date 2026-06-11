#include <bits/stdc++.h>

using namespace std;


int main() {
    map<int, int> a, b;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int d;
        cin >> d;
        a[d]++;
    }
    int m;
    cin >> m;
    for(int i = 0; i < m; i++) {
        int t;
        cin >> t;
        b[t]++;
    }
    for(auto c : b) {
        int x = c.first, y = c.second;
        if(a[x] < y) {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    return 0;
}