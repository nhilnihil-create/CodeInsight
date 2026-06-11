#include <bits/stdc++.h>
#define FOR(i, l, r) for(ll i = l; i < r; i++)
#define rep(i, N) FOR(i, 0, N)
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<ll> vl;
const ll MOD = round(1e9+7);

int main() {
    vi col(3);
    rep(i,3) cin >> col[i];
    int N;
    cin >> N;

    ll ans = 0;
    sort(col.begin(), col.end());
    rep(i,N/col[2]+1){
       int tmp = N-i*col[2];
       if(tmp < 0) break;
       rep(j,tmp/col[1]+1){
           if(tmp-col[1]*j < 0) break;
           if((tmp-col[1]*j)%col[0] == 0) ans++;
       } 
    }


    cout << ans << endl;
    return 0;
}
