#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//cout << fixed << setprecision(17) << res << endl;
 
int main() {
    ll n, k;
    cin >> n >> k;
    ll res = (n-1)/(k-1);
    if ((n-1)%(k-1) != 0) ++res;
    cout << res << endl;
}
