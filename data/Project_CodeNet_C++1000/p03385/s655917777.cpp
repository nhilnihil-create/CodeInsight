#include <bits/stdc++.h>

#define rep(l, r) for (int i = (l); i < (r); i++)

typedef long long ll;
 
using namespace std;

int main() {
    string s;
    cin >> s;

    sort(s.begin(), s.end());

    cout << (s == "abc" ? "Yes" : "No") << endl;

    return 0;
}
