#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)
double const PI = 3.1415926535897932384626433;
using P = pair<int, int>;

int main() {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    if (s == "abc")
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}