#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
typedef long long ll;
const int INT_INF = 1e9;
const ll INF = 1LL << 30;
const ll MOD = 1e9 + 7;


int main() {
    int n; cin >> n;
    string s; cin >> s;
    V<int> w(n, 0), e(n, 0);
    if(s[0] == 'W') w[0] = 1;
    else e[0] = 1;
    for(int i = 1; i < n; i++){
        if(s[i] == 'W'){
            w[i] = w[i - 1] + 1;
            e[i] = e[i - 1];
        }else{
            e[i] = e[i - 1] + 1;
            w[i] = w[i - 1];
        }
    }

    int ans = INT_INF;
    for(int i = 0; i < n; i++){
        int l = 0, r = 0;
        if(0 < i) l = w[i];
        r = e[n - 1] - e[i + 1];
        ans = min(ans, l + r);
    }
    cout << ans << endl;

}
