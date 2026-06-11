#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <set>
#include <algorithm>
#include <iomanip>

typedef long long ll;
const ll MOD = 10007;
const long long INF = 1LL<<60;
const double PI=3.14159265358979323846;
const int NMAX=100005;
using namespace std;


int main(){
    ll n,m,Q;
    cin >> n >> m >> Q;
    ll lr[n+1][n+1];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            lr[i][j] = 0;
        }
    }
    vector<ll> p(Q), q(Q);
    for(int i = 0; i < m; i++){
        ll tl, tr;
        cin >> tl >> tr;
        lr[tl][tr]++;
    }
    for(int i = 0; i < Q; i++){
        cin >> p[i] >> q[i];
    }

    ll suml[n+1][n+1];
    for(int i = 1; i <= n; i++){
        suml[i][0] = 0;
        for(int j = 1; j <= n; j++){
            suml[i][j] = suml[i][j-1] + lr[i][j];
        }
    }

    for(int i = 0; i < Q; i++){
        ll ans = 0;
        for(int j = p[i]; j <= q[i]; j++){
            ans += suml[j][q[i]] - suml[j][p[i]-1];
        }
        cout << ans << endl;
    }

    return 0;
}