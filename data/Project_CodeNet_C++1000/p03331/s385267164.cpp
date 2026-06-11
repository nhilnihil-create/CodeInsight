#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define FOR(i,s,n) for(int i = (s); i < (n); i++)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) for(int i = (n); i >= 0; i--)
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
    auto ketawa = [](const int x) {
        int ret = 0;
        string s = to_string(x);
        for (auto c:s) ret += c - '0';
        return ret;
    };

    int N; cin >> N;
    int ans = 1<<30;
    FOR(i,1,N/2+1) ans = min(ans,ketawa(i)+ketawa(N-i));

    cout << ans << '\n';

    return 0;
}