#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define FOR(i,s,n) for(int i = s; i < (n); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(n) (n).begin(), (n).end()
#define RALL(n) (n).rbegin(), (n).rend()
#define ATYN(n) cout << ( (n) ? "Yes":"No") << '\n';
#define CFYN(n) cout << ( (n) ? "YES":"NO") << '\n';
#define OUT(n) cout << (n) << '\n';
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

int main(void)
{
    IOS
    const char B = '#';
    const char W = '.';
    
    int n; cin >> n;
    string s; cin >> s;
    int b = 0, w = 0, lb = 0, rw = 0;
    REP(i,n) {
        if (s[i] == B) b++;
        else w++;
    }

    int ans = min(b,w);
    rw = w;
    REP(i,n) {
        if (s[i] == B) lb++;
        else rw--;
        ans = min(ans,rw+lb);
    }

    cout << ans << '\n';


    return 0;
}