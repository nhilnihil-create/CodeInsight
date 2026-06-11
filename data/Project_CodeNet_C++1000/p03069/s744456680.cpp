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
    int n; cin >> n;
    string s; cin >> s;

    int wcnt = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '.') wcnt++;
    }

    int ans = wcnt;
    int b = 0, w = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '#') b++;
        if(s[i] == '.') w++;
        ans = min(ans, b + wcnt - w);
    }
    cout << ans << endl;


    return 0;
}
