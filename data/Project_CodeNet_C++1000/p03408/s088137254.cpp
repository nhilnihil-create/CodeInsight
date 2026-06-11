#include<bits/stdc++.h>
#include <numeric>
// #define int long long
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
using namespace std;
using ll = long long;
typedef vector<int> vi;

signed main() {
    int n, m;
    cin >> n;
    map<string, int> table;
    rep(i, n){
        string s;
        cin >> s;
        table[s]++;  
    }
    cin >> m;
    rep(i, m){
        string t;
        cin >> t;
        table[t]--;
    }

    int ans = 0;
    for(auto i = table.begin(); i != table.end(); i++){
        ans = max(ans, i->second);
    }

    cout << ans << endl;
}