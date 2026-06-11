#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<iomanip>
using namespace std;
using ll = long long;

int main() {
    ll n,m,d;cin>>n>>m>>d;
    double half;
    if (d==0) half = n;
    else half = 2 * (n - d);
    double ans = (double)(half) * (double)(m -1) / (double)(n * n);
    cout << setprecision(9) << ans << endl;
    return 0;
}