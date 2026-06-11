#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0, i##_len = (int)(n); i < i##_len; i++)

int main() {
    vector<int> a(4, 0);
    rep(i, 6) {
        int x;
        cin >> x;
        x--;
        a[x]++;
    }
    bool valid = (*max_element(a.begin(), a.end()) <= 2);
    cout << (valid ? "YES" : "NO") << endl;
}
