#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll n, m, d;
    cin >> n >> m >> d;
    double dn = n, dm = m, dd = d;
    double ans;
    if(d == 0) ans = (dm - 1) / dn;
    else ans = (dm - 1) * 2.0 * (dn - dd) / (dn * dn);
    printf("%.10lf\n", ans);
    return 0;
}