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

    int sume = 0, sumw = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'W') sumw++;
        else sume++;
    }

    int e = 0, w = 0;
    int ans = 1e9;
    for(int i = 0; i < n; i++){
        if(s[i] == 'E') e++;
        ans = min(ans, w + sume - e);
        if(s[i] == 'W') w++;
    }
    cout << ans << endl;

    return 0;
}
