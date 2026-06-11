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
    const string K = "keyence";
    string s; cin >> s;

    auto pos = s.find(K);
    if (pos != string::npos) {
        CFYN(true)
        return 0;
    } else {
        FOR(i,1,K.size()-1) {
            bool ok = true;
            REP(j,i) {
                if (s[j] != K[j]) ok = false;
            }
            REP(j,K.size()-i-1) {
                if (s[s.size()-j-1] != K[K.size()-j-1]) ok = false;
            }
            if (ok) {
                CFYN(true)
                return 0;
            }
        }
    }

    CFYN(false)

    return 0;
}