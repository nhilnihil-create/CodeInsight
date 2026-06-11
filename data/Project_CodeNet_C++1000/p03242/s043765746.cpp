#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)
double const PI = 3.1415926535897932384626433;

int main() {
    string s;
    cin >> s;
    rep(i, 3) {
        if (s[i] == '1')
            cout << 9;
        else if (s[i] == '9')
            cout << 1;
    }
    cout << endl;
    return 0;
}