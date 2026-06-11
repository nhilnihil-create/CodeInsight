#include <bits/stdc++.h>

#define rep(l, r) for (int i = (l); i < (r); i++)

typedef long long ll;
 
using namespace std;

int main() {
    string s;
    cin >> s;

    cout << (700 + 100 * count(s.begin(), s.end(), 'o')) << endl;

    return 0;
}
