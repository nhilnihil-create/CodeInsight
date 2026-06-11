#include <bits/stdc++.h>
using namespace std;

//#define int long long
typedef long long ll;
//const int INF = 2e9;
//const ll INF = 9e18;


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    double n, m, d;
    cin >> n >> m >> d;
    cout << fixed << setprecision(9);
    if (d == 0){
        cout << (m-1.0)/n << "\n";
    } else {
        cout << 2.0*(m-1)*(n-d)/n/n << "\n";
    }
}