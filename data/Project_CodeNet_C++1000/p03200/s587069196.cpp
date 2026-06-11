#include<bits/stdc++.h>
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
    ll bcnt = 0, cnt = 0;
    rep(i, s.length()){
        if(s[i] == 'B') bcnt++;
        else if(s[i] =='W') cnt += bcnt;
    }

    cout << cnt << endl;
}