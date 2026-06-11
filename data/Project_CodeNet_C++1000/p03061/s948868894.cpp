#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int N; cin >> N;
    vector<int> A(N);
    rep(i, N){
        cin >> A[i];
    }

    vector<int> L(N);
    L[0] = A[0];
    for (int i = 1; i < N; i++){
        L[i] = __gcd(L[i-1], A[i]);
    }

    vector<int> R(N);
    R[N-1] = A[N-1];
    for (int i = N-2; i >= 0; i--){
        R[i] = __gcd(R[i+1], A[i]);
    }

    int ans = 1;
    for (int i = 0; i < N; i++){
        if(i == 0){
            int x = R[1];
            ans = max(ans, x);
        } else if(i == N-1){
            int x = L[N-2];
            ans = max(ans, x);
        } else {
            int x = __gcd(L[i-1], R[i+1]);
            ans = max(ans, x);
        }
    }

    cout << ans << endl;


    return 0;
}