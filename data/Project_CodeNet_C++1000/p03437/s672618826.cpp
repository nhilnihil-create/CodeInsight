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

ll gcd(ll a,ll b){
    if (a % b == 0) {
        return b;
    } else {
        return gcd(b,a%b);
    }
}

ll lcm(ll x, ll y) {
    return x / gcd(x,y) * y;
}

int main(void)
{
    IOS
    ll X, Y;
    cin >> X >> Y;
    if (gcd(X,Y) == Y) OUT(-1)
    else OUT(X)

    return 0;
}