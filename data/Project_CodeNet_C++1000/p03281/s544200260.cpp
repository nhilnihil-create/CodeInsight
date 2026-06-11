#include <bits/stdc++.h>
using namespace std;
#define FOR(i, l, r) for(ll i = l; i < (r); i++)
#define rep(i, N) FOR(i, 0, N)

typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<ll> vl;
const ll MOD = round(1e9+7);

int main() {
    int N; cin >> N;
    int ans = 0;

    rep(i,N){
        if(i+1 < 105) continue;
        int num = i+1;
        if(num%2==0) continue;
        int tmp = 0;
        rep(j,num){
            if(num % (j+1) == 0) tmp++;
        }
        if(tmp == 8) ans++;
    }

    cout << ans << "\n";
    return 0;
}
