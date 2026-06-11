#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    vector<int> w(n+1);
    vector<int> e(n+1);
    for (int i = 0; i < n; i++) {
        if (s.at(i) == 'W') {
            w.at(i+1) = w.at(i) + 1;
        } else {
            w.at(i+1) = w.at(i);
        }
    }

    for (int i = 0; i < n; i++) {
        if (s.at(i) == 'E') {
            e.at(i+1) = e.at(i) + 1; 
        } else {
            e.at(i+1) = e.at(i);
        }
    }

    int ans = n;
    for(int i = 0; i < n; i++) {
        ans = min(ans, w[i] + e[n] - e[i+1]);
    }
    cout << ans << endl;
}