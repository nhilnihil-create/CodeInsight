#include <bits/stdc++.h>
const int INF = 1e9;
const int MOD = 1e9+7;
const long long LINF = 1e18;
#define dump(x)  cout << 'x' << ' = ' << (x) << ` `;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define FOREACH(x,a) for(auto& (x) : (a) )
typedef long long ll;
using namespace std;
typedef pair<ll, ll> P;

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    vector<ll> a(n);
    REP(i,n) cin >> a[i];
    sort(a.begin(), a.end());

    ll ans1 = a.back();
    ll mid = ans1/2;
    ll ans2 = LINF;
    REP(i,n-1) {
        if (abs(mid-a[i]) <= abs(mid-ans2)) {
            ans2 = a[i];
        } 
    }

    cout << ans1 << " " << ans2 << endl;
    return 0;
}