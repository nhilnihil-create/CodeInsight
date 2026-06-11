#include<bits/stdc++.h>
using namespace std;
const double EPS = 1e-10;

int main(){
    double n, m, d; cin >> n >> m >> d;
    double ans = 2 * (n - d) * (m - 1) / n / n;
    if(d < EPS) ans /= 2;
    cout << fixed << setprecision(10);
    cout << ans << endl;
    return 0;
}