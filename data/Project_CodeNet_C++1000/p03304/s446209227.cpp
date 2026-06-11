#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;
const ll INF = 1001001001;

ll N, M, D, tmp=0;
vector<ll> A;

signed main(){
    cin >> N >> M >> D;
    double ans;
    if(D==0) {
        ans = ((double)M-1.0)/(double)N;
    }
    else {
        ans = 2.0*((double)M-1.0)*(1.0-(double)D/(double)N)/(double)N;
    }
    cout << fixed << setprecision(8) << ans << endl;
    return 0;
}