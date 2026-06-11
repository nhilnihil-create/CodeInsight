
#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (ll (i) = 0 ; (i) < (ll)(n) ; ++(i))
#define REPN(i, m, n) for (ll (i) = m ; (i) < (ll)(n) ; ++(i))
#define REP_REV(i, n) for (ll (i) = (ll)(n) - 1 ; (i) >= 0 ; --(i))
#define REPN_REV(i, m, n) for (ll (i) = (ll)(n) - 1 ; (i) >= m ; --(i))

#define INF             2e9
#define INF_LL          1LL<<60
#define ll              long long
#define Ceil(x, n)      (((((x))+((n)-1))/n))
#define CeilN(x, n)     (((((x))+((n)-1))/n)*n)
#define FloorN(x, n)    ((x)-(x)%(n))
#define ALL(x)          (x).begin(),(x).end()
typedef pair<ll, ll>    P;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    REP(i, n) {
        int tmp;
        cin >> tmp;
        tmp--;
        a[tmp] = i;
    }
    int ans = 1;
    int tmp2 = 1;

    REP(i, n-1) {
        if(a[i+1] > a[i]) tmp2++;
        else {
            ans = max(tmp2, ans);
            tmp2 = 1;
        }
    }
    ans = max(tmp2, ans);
    cout << n - ans << endl;
    return 0;
}