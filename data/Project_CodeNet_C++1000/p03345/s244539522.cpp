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
    ll A,B,C;
    cin >> A >> B >> C;
    ll K; cin >> K;
    if (K % 2 == 0) OUT(A-B)
    else OUT(B-A)

    return 0;
}