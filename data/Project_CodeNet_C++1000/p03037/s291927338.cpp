#include <bits/stdc++.h>
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
#define ALL(x) (x).begin(),(x).end() 
#define SIZE(x) ((ll)(x).size())
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define INF 1000000000
using namespace std;
typedef long long ll;

int main() {
    int N, M;
    cin >> N >> M;

    int L[M], R[M], Lmax = 0, Rmin = 1e+9;
    REP(i, M){
        cin >> L[i] >> R[i];

        Lmax = max(Lmax, L[i]);
        Rmin = min(Rmin, R[i]);
    }

    int ans = 0;
    if (Rmin - Lmax >= 0) ans = Rmin - Lmax + 1;
    else ans = 0;

    cout << ans << endl;
}