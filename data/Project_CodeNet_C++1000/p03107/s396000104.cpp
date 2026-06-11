#include<bits/stdc++.h>
#include <numeric>
// #define int long long
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
#define MOD 1000000007
using namespace std;
using ll = long long;
typedef vector<int> vi;

signed main() {
    string s;
    cin >> s;
    int r = 0, b = 0;
    rep(i, s.length()){
        if(s[i] =='0') r++;
        else if(s[i] == '1') b++;
    }
    /* cout << r << " " << b << " "; */
    cout << 2 * min(r, b) << endl;
}