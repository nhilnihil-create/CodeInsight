#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    if (n == 3) {
        cout << "2 5 63" << endl;
        return 0;
    }
    else if (n == 4) {
        cout << "2 5 20 63" << endl;
        return 0;
    }
    else if (n == 5) {
        cout << "2 3 4 5 16" << endl;
        return 0;
    }

    vector<int> v;
    for (int i = 0; i < 30000 / 6; i++) {
        v.push_back(i * 6 + 2);
        v.push_back(i * 6 + 3);
        v.push_back(i * 6 + 4);
        v.push_back(i * 6 + 6);
    }

    vector<int> ans(n);
    long long s = 0;
    for (int i = 0; i < n; i++) {
        s += (long long)v.at(i);
        ans.at(i) = v.at(i);
    }

    if (s % 6 == 0) {
        for (auto x: ans) {
            cout << x << " ";
        }
        cout << endl;
    }
    else if (s % 6 == 2) {
        for (auto x: ans) {
            if (x == 2) cout << 30000 << " ";
            else cout << x << " ";
        }
        cout << endl;
    }
    else if (s % 6 == 3) {
        for (auto x: ans) {
            if (x == 3) cout << 30000 << " ";
            else cout << x << " ";
        }
        cout << endl;
    }
    else if (s % 6 == 5) {
        for (auto x: ans) {
            if (x == 3) cout << 29998 << " ";
            else cout << x << " ";
        }
        cout << endl;
    }
}