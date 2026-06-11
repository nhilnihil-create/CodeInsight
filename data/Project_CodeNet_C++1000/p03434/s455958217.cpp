#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
    }
    sort(a.begin(), a.end(), greater<int>());
    int alice = 0, bob = 0;
    for (int i = 0; i < n; i += 2) {
        alice += a.at(i);
    }
    for (int i = 1; i < n; i += 2) {
        bob += a.at(i);
    }
    cout << alice - bob << endl;
    return 0;
}