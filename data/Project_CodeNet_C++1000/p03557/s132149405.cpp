#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<ll> A(N), B(N), C(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for(int i = 0; i < N; i++) {
        cin >> B[i];
    }

    for(int i = 0; i < N; i++) {
        cin >> C[i];
    }

    sort(A.begin(), A.end());
    sort(C.begin(), C.end());
    ll ans = 0;
    for(int  i = 0; i < N; i++) {
        auto Iter1 = lower_bound(A.begin(), A.end(), B[i]);
        
        auto Iter2 = upper_bound(C.begin(), C.end(), B[i]);
        ans += (C.end() - Iter2) * (Iter1 - A.begin());
        
    }
    cout << ans << endl;

    return 0;
}