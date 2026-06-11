#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

struct cake {
    ll x;
    ll y;
    ll z;
};

int main() {
    ll N, M; cin >> N >> M;
    vector<cake> V(N);
    rep(i, N){
        cin >> V[i].x >> V[i].y >> V[i].z;
    }

    ll ans = 0;
    for (int i = 0; i < 8; i++){
        vector<ll> A;
        for (int j = 0; j < N; j++){
            ll now = 0;
            if(i>>0&1){
                now += V[j].x;
            } else {
                now -= V[j].x;
            }
            if(i>>1&1){
                now += V[j].y;
            } else {
                now -= V[j].y;
            }
            if(i>>2&1){
                now += V[j].z;
            } else {
                now -= V[j].z;
            }
            A.push_back(now);
        }
        sort(A.begin(), A.end());
        reverse(A.begin(), A.end());

        ll total = 0;
        for (int k = 0; k < M; k++){
            total += A[k];
        }

        ans = max(ans, total);

    }

    cout << ans << endl;




    return 0;
}