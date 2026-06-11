#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define ALL(c) (c).begin(), (c).end()
const int MOD = 1000000007;


int main() {
    string s;
    int w;
    cin >> s >> w;
    for (int i = 0; i < s.size(); i += w) {
        cout << s[i];
    }
    cout << endl;
}
