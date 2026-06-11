#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,m,d; cin >> n >> m >> d;
    if (m<2){cout << 0 << '\n'; return 0;}
    ll sum=max(n-d,0LL)*2*(m-1);
    if (d==0) sum/=2;
    cout << fixed << setprecision(10);
    cout << (double)sum/(double)(n*n) << '\n';
}