#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.size();
    int zero = count(s.begin(), s.end(), '0');

    cout << min(zero, n - zero) * 2 << endl;
    return 0;
}
