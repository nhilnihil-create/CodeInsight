#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N), d(N, 0);
    rep(i, 0, N) cin >> A[i];
    // Check if -1
    if(A[0] > 0){
        cout << -1 << endl;
        return 0;
    }
    // main
    ll ans = A[N-1];
    rep(i, 1, N){
        if(A[i] == A[i-1] + 1){
            ;
        }else if(A[i] > A[i-1] + 1){
            cout << -1 << endl;
            return 0;
        }else{
            // A[i] + 1 < A[i+1]
            ans += A[i-1];
        }
    }
    cout << ans << endl;
    return 0;
}