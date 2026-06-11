#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define ALL(x) (x).begin(),(x).end()
const int IINF = 1e9;
const LL LINF = 1e18;
const LL MOD = 1e9+7;

int main() {
    int N;
    cin >> N;
    double k = 0;
    REP(i, N) {
        double x;
        string u;
        cin >> x >> u;
        k += u == "JPY" ? x : x*380000;
    }
    printf("%.8f\n", k);
    return 0;
}
