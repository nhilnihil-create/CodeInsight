#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int64_t> l(n+1);
    l.at(0) = 2;
    l.at(1) = 1;
    for (int i = 2; i <= n; i++) {
        l.at(i) = l.at(i-1) + l.at(i-2);
    }

    cout << l.at(n) << endl;
    return 0;

}