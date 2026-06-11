#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;

ll sqrt(ll in){
    ll ok = 0;
    ll ng = 1e9 + 1;
    while(ng - ok > 1){
        ll mid = (ok + ng) / 2;
        if(mid * mid < in){
            ok = mid;
        } else {
            ng = mid;
        }
    }
    return ok;
}

int main() {
    //cout.precision(10);
    int n;
    cin >> n;
    for(int time = 0; time < n; time++){
        ll a, b;
        cin >> a >> b;
        if(a > b) swap(a, b);
        if((a == 1) && (b == 1)){
            cout << 0 << endl;
            continue;
        }
        ll checker = sqrt(a * b);
        ll ans = 2 * checker;
        if(checker >= a){
            ans--;
        }
        if(checker * (checker + 1) >= (a * b)){
            ans--;
        }
        cout << ans << endl;
    }
    return 0;
}
