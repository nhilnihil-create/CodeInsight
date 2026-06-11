#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    if (A[0] != 0) {
        cout << -1 << endl;
        return 0;
    }
    ll ans = 0;
    for (int i = 1; i < N; i++) {
        if (A[i] > A[i-1] + 1) {
            cout << -1 << endl;
            return 0;
        }
    }
    for (int i = 0; i < N-1; i++) {
        if (A[i] + 1 == A[i+1]) continue;
        ans += A[i];
    }
    ans += A[N-1];
    
    cout << ans << endl;
    return 0;
}