#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int main() {
    ll n, m, d; cin >> n >> m >> d;
    double ans = 0;
    if(d==0) ans = 1.0*(m-1)/n;
    else ans = 2.0*(n-d)/n * (m-1)/n;
    printf("%.10f\n", ans);
}
