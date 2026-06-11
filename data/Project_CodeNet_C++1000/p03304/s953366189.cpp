#include <bits/stdc++.h>
using namespace std;
#define REP(i,a) for(int i = 0; i < (a); i++)
#define ALL(a) (a).begin(),(a).end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const long long LINF = 1e18;
const long long MOD = 1e9 + 7;

signed main(){
    double n,m,d;
    cin >> n >> m >> d;
    if(d == 0) printf("%.10lf\n", (m - 1) * (n - d) / pow(n, 2));
    else printf("%.10lf\n", 2 * (m - 1) * (n - d) / pow(n, 2));
    return 0;
}