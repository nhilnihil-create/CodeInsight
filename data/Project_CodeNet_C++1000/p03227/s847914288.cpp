#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;
using ld = long double;
const int MOD = 1e9+7;
const ll INF = 1LL << 60;


int main() {
    string s; cin >> s;
    string t = s;
    reverse(ALL(t));
    if(s.size() == 2) cout << s << endl;
    else cout << t << endl;

    return 0;
}
