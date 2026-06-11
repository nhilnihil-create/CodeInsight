#include <bits/stdc++.h>
using namespace std;
#define REP(i,a) for(int i = 0; i < (a); i++)
#define ALL(a) (a).begin(),(a).end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const long long LINF = 1e18;
const long long MOD = 1e9 + 7;

#define MAX_K 100000

int k;
ll a[MAX_K];

bool isOK(ll n, bool fi){
    REP(i,k){
        n = n - n % a[i];
    }
    if(fi) return n >= 2;
    else return n <= 2;
}

signed main(){
    cin >> k;
    REP(i,k){
        cin >> a[i];
    }
    ll ng = -1, ok = LINF;
    while(abs(ok - ng) > 1){
        ll mid = (ng + ok) / 2;
        if(isOK(mid, true)){
            ok = mid;
        }else{
            ng = mid;
        }
    }
    ll ans = ok;
    ng = LINF, ok = -1;
    while(abs(ok - ng) > 1){
        ll mid = (ng + ok) / 2;
        if(isOK(mid, false)){
            ok = mid;
        }else{
            ng = mid;
        }
    }
    if(ans > ok) cout << -1 << endl;
    else cout << ans << " " << ok << endl;
    return 0;
}