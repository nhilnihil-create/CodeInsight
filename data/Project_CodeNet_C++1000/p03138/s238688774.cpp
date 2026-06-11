#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    int N; cin >> N;
    ll K; cin >> K;
    vector<ll> A(N);
    rep(i, N){
        cin >> A[i];
    }

    ll ans = 0;
    for (int i = 40; i >= -1; i--){
        if(i != -1 && !(K>>i&1))continue;

        ll tmp = 0;
        for (int j = 40; j >= 0; j--){
            ll mask = 1LL<<j;
            ll num = 0;
            rep(i, N){
                if(A[i]&mask)num++;
            }

            if(j > i){
                if(K&mask){
                    tmp += mask*(N-num);
                } else {
                    tmp += mask*num;
                }
            } else if(j == i){
                tmp += mask*num;
            } else {
                tmp += mask * max(num, N-num);
            }
        }
        ans = max(ans, tmp);
    }

    cout << ans << endl;


    
    return 0;
}