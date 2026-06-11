#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)
double const PI = 3.1415926535897932384626433;
using P = pair<int, int>;

int main() {
    int mi = 1e9;
    string s;
    cin >> s;
    for (int i = 0; i <= s.size() - 3; ++i) {
        int tmp = abs(753 - stoi(s.substr(i, 3)));
        mi = min(mi, tmp);
    }
    cout << mi << endl;
    return 0;
}