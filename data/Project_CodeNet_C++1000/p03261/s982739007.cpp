#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    string res = "Yes";
    char tail;
    vector<string> w(n);
    for (int i = 0; i < n; i++) {
        cin >> w.at(i);
        if (i != 0) {
            if (tail != w.at(i).at(0)) res = "No";
        }
        tail = w.at(i).at(w.at(i).size()-1);
    }

    sort(w.begin(), w.end());
    for (int i = 1; i < n; i++) {
        if (w.at(i-1) == w.at(i)) res = "No";
    }

    cout << res << endl;

    return 0;
}
