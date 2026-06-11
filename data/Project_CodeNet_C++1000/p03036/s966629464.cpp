#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    int r , d , cur;
    cin >> r >> d >> cur;

    for (int i = 0 ;i < 10 ;i++) {
        cur = r * cur - d;
        cout << cur << '\n';
    }
}