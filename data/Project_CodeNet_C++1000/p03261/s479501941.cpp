#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    vector<string> w(n);
    map<string, int> m;
    for (int i = 0; i < n; i++) {
        cin >> w.at(i);
        m[w.at(i)]++;
    }
    for (int i = 1; i < n; i++) {
        if (m[w.at(i)] > 1) {
            cout << "No" << endl;
            return 0;
        }
        if (w.at(i - 1).back() != w.at(i).front()) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}