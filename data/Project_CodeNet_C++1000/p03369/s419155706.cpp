#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;
using ld = long double;
const int MOD = 1e9+7;


int main() {
    string s; cin >> s;
    int ans = 700;
    if(s[0] == 'o') ans+=100;
    if(s[1] == 'o') ans+=100;
    if(s[2] == 'o') ans+=100;
    cout << ans << endl;

    return 0;
}
