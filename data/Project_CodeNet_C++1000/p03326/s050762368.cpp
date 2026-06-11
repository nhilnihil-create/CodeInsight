#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

const long MOD = 1000000007;
typedef pair<int, int> P;
typedef long long ll;

int main(){
    int N, M;
    cin >> N >> M;

    ll x[N], y[N], z[N];
    for(int i=0; i<N; i++) cin >> x[i] >> y[i] >> z[i];

    ll ans = 0;
    for(int d=0; d<8; d++){
        int dx = pow(-1, ((d>>0)&1));
        int dy = pow(-1, ((d>>1)&1));
        int dz = pow(-1, ((d>>2)&1));

        ll sum[N];
        fill(sum, sum+N, 0);
        for(int i=0; i<N; i++){
            sum[i] = x[i]*dx + y[i]*dy + z[i]*dz;
        }
        sort(sum, sum+N, greater<ll>());

        ll t = 0;
        for(int i=0; i<M; i++){
            t = t + sum[i];
        }
        ans = max(t, ans);
    }

    cout << ans << endl;

    return 0;
}
