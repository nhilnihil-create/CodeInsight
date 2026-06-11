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
    sort(A.begin(), A.end());
    A.emplace_back(-1);
    int ans = 0, tmp = 0, cnt = 0;
    rep(i,N+1){
        if(A[i] != tmp){
            ans += (cnt >= tmp?cnt - tmp:cnt);
            tmp = A[i];
            cnt = 1;
        }else{
            cnt++;
        }
    }

    cout << ans << endl;
    return 0;
}
