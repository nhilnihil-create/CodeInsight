#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> v(100,0);
    for (int i = 0; i < N; i++) {
        int j; cin >> j;
        v.at(j - 1) = j;
    }

    int ans = 0;
    for (int i = 0;i < 100; i++) {
        if (v.at(i) != 0) ans++;
    }

    cout << ans << endl;

}