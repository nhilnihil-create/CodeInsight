#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef pair<ll, pair<ll, ll> > P3;

const ll MOD = ll(1e9 + 7);
const ll LLINF = LLONG_MAX;
const int IINF = INT_MAX;
const int MAX_N = int(3e5) + 5;
const double EPS = 1e-8;
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
#define SORT(v) sort((v).begin(), (v).end())
#define SORTR(v) sort((v).rbegin(), (v).rend())
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (ll i = m; i < n; i++)
#define ALL(v) (v).begin(), (v).end()

ull n, x, a[MAX_N], cum[MAX_N]{};

int main() {
    cin >> n >> x;
    REP(i,n){
        cin >> a[i];
        cum[i+1] += cum[i]+a[i];
    }
    ull ans = LLINF;
    for(ull i=1ull;i<=n;i++){
        ull tmp = 5ull*cum[n], k = n - i;
        while(1){
            if(k<=i)break;
            k -= i;
            tmp += 2*cum[k];
        }
        tmp += (n+i)*x;
        ans = min(ans,tmp);
    }
    cout << ans << endl;
    return 0;
}
