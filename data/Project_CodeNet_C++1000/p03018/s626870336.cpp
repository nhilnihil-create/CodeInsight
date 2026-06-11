#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define REP(i,n) FOR(i,0,n)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vvvi = vector<vector<vector<int>>>;
using mii = map<int, int>;
using msi = map<string, int>;
using pii = pair<int, int>;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << std::fixed << std::setprecision(10);
    
    string s;cin >> s;
    ll ans = 0;
    ll cnt = 0;
    bool f = false;
    REP(i, s.size()) {
        if(s[i] == 'A') {
            if(f) cnt = 0;
            cnt++;
            f = false;
        }
        if(s[i] == 'B') {
            if(f) cnt = 0;
            f = true;
        }
        if(s[i] == 'C') {
            if(f) ans += cnt;
            else cnt = 0;
            f = false;
        }
    }
    cout << ans << endl;
    

    return 0;
}