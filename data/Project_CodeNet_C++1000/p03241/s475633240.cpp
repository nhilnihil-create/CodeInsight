#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )
#define FOR(i, m, n) for(int i = m; i < n; i++)
 
typedef pair<int,int> P;
typedef long long ll;
 
const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);

int main(){
    ll N,M;
    cin >> N >> M;

    ll ans = 1;

    for (ll i=1; i<=M; i++) {
        if (i*i>M) {
            if (N==1) {
                ans = M;
            }
            break;
        }
        else {
            if (M%i==0) {
                if (M/i>=N) ans = max(ans,i);
                ll j = M/i;
                if (M/j>=N) ans = max(ans,j);
            }
        } 
    }
    
    cout << ans << endl;
}
