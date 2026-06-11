#include <bits/stdc++.h>

#define rep(x, y) for (int i = (x); i < (y); i++)

typedef long long ll;

using namespace std;

int main() {
    string n;
    cin >> n;

    rep(0, n.size()) {
        switch (n[i]) {
            case '1':
                cout << '9';
                break;
            case '9':
                cout << '1';
                break;
        }
    }
    cout << endl;

    return 0;
}
