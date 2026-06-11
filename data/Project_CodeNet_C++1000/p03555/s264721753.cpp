#include <bits/stdc++.h>

#define rep(l, r) for (int i = (l); i < (r); i++)

typedef long long ll;
 
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    string rs1 = s1, rs2 = s2;
    reverse(rs1.begin(), rs1.end());
    reverse(rs2.begin(), rs2.end());

    cout << (s1 == rs2 && s2 == rs1 ? "YES" : "NO") << endl;

    return 0;
}
