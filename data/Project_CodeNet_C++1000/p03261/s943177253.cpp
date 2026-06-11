#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;

    vector<string> w(n);
    rep(i,n) {
        cin >> w.at(i);
    }

    char lastChar=w.at(0)[w.at(0).size()-1];
    for (int i=1; i<n; i++) {
        rep(j, i) {
            if (w.at(j) == w.at(i)) {
                cout << "No" << endl;
                return 0;
            }
        }
        if (lastChar != w.at(i)[0]) {
            cout << "No" << endl;
            return 0;
        }
        lastChar = w.at(i)[w.at(i).size()-1];
    }

    cout << "Yes" << endl;
    return 0;
}