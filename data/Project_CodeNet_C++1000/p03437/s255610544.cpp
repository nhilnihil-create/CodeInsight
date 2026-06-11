#include <bits/stdc++.h>
#include <algorithm>
#include<string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long X, Y;
    cin >> X >> Y;
    if (X % Y == 0) {
        cout << -1 << endl;
    } else {
        cout << X << endl;
    }
    return 0;
}
