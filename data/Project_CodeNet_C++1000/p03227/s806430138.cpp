#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    string s;
    cin >> s;
    if (s.size() == 3) reverse(s.begin(), s.end());
    cout << s << endl;

    return 0;
}
