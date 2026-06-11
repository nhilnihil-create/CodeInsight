#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define FOR(i,s,n) for(int i = s; i < (n); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(n) (n).begin(), (n).end()
#define RALL(n) (n).rbegin(), (n).rend()
#define ATYN(n) cout << ( (n) ? "Yes":"No") << endl;
#define CFYN(n) cout << ( (n) ? "YES":"NO") << endl;
#define OUT(n) cout << (n) << endl;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;

int main(void)
{
    IOS
    ll n, k;
    cin >> n >> k;

    ll ans = 0;
    if (k == 0) ans = n*n;
    else FOR(i,k+1,n+1) {
            if (n/i*i+k<=n) {
                //cerr << n/i*i+k << endl;
                ans += n/i * (i-k) + (n-n/i*i-k+1);
            } else {
                ans += n/i * (i-k);
            }
            //cerr << ans << endl;
        }

    cout << ans << endl;

    return 0;
}