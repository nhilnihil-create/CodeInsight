#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    double n, m, d; cin >> n >> m >> d;

    if(d != 0)cout << setprecision(10) << fixed << 2.0 * ( n - d ) * (m - 1) / pow(n, 2) << endl;
    else cout << setprecision(10) << fixed <<  n * (m - 1) / pow(n, 2) << endl;
}