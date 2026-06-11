#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)
double const PI = 3.1415926535897932384626433;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    if (s1[0] == s2[2] && s1[1] == s2[1] && s2[0] == s1[2])
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}