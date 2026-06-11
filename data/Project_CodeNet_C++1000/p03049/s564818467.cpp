#include <bits/stdc++.h>
using namespace std;
 
using ll=long long;
 
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)
#define pb push_back
#define eb emplace_back
#define a first
#define b second
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
const ll MOD = 998244353;


int main() {
    int n; 
    cin >> n;
    int cnt = 0, cnta = 0, cntb = 0, cntba = 0;
    rep(i, n) {
        string s;
        cin >> s;
        rep(j, s.size()-1) if (s[j] == 'A' && s[j+1] == 'B') ++cnt;
        if (s[s.size()-1] == 'A') {
            if (s[0] == 'B') ++cntba;
            else ++cnta;
        } else {
            if (s[0] == 'B') ++cntb;
        }
    } 

    if (cntba == 0) {
        cnt += min(cnta, cntb);
    } else {
        if (cnta + cntb > 0) cnt += cntba + min(cnta, cntb);
        else cnt += cntba-1;
    }
    cout << cnt << endl;
    return 0;
}