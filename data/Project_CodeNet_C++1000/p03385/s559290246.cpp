#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    string s;
    cin >> s;

    if (count(s.begin(), s.end(), 'a') && count(s.begin(), s.end(), 'b') &&
        count(s.begin(), s.end(), 'c'))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
