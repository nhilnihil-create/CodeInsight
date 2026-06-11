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

typedef pair<int, int> P;

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    vector<ll> a(n);
    REP(i,n) cin >> a[i];
    sort(a.begin(), a.end(), greater<>());
    ll N = a[0];
    ll mid = (N+2-1)/2;
    ll absR = LINF;
    ll R = 0;
    for (int i = 1; i < n; ++i) {
        if (absR > abs(a[i]-mid)) {
            R = a[i];
            absR = abs(a[i]-mid);
        }
    }
    cout << N << " " << R << endl;
    return 0;
}