#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e18;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    double n,m,d;
    cin >> n >> m >> d;
    if(d == 0) {
        cout << fixed << setprecision(20) << (m-1)*((n-d)/(n*n)) << endl;
    }
    else {
        cout << fixed << setprecision(20) << (m-1)*((n-d)*2/(n*n)) << endl;
    }
}
