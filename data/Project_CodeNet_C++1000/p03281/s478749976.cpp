// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

#define rep(i, s, n) for (int i = s; i < (int)(n); i++)
using namespace std;
// using ll = long long int;

void inv(vector<int>& v) {
    int length = v.size();
    for (int i = 0; i < length; i++) {
        cin >> v[i];
    }
}
void inv(vector<int>& v, int length) {
    for (int i = 0; i < length; i++) {
        cin >> v[i];
    }
}

int main() {
    int n;
    cin >> n;

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (i % 2 != 1) continue;

        int cnt = 0;
        for (int j = 1; j <= i; j++) {
            if (i % j == 0) cnt++;
        }
        if (cnt == 8) ans++;
    }

    cout << ans << endl;

    return 0;
}
