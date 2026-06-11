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
    int N; cin >> N;
    vi A(N); rep(i,N) cin >> A[i];
    ll ans = 0;
    if(A[0] != 0) {
        cout << -1;
        return 0;
    }

    ll tmp = 0;
    rep(i,N){
        if(i == N-1) {
            ans += A[i];
            break;
        }
        if(A[i+1] <= tmp){
            ans += tmp;
        }else if(A[i+1] != tmp+1) {
            cout << -1;
            return 0;
        }
        tmp = A[i+1];
    }

    cout << ans;
    return 0;
}
