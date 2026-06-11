#include <bits/stdc++.h>

#define rep(l, r) for (int i = (l); i < (r); i++)

typedef long long ll;
 
using namespace std;

void solve() {
    string s;
    cin >> s;

    int n = 0;
    rep(0, s.size()) {
        switch (s[i]) {
            case '+':
                n++;
                break;
            case '-':
                n--;
                break;
        }
    }

    cout << n << endl;
}

int main() {
    solve();

    return 0;
}
