#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];
    ll ans = 0;
    for (int i = 29; i >= 0; i--) {
        int t = (1 << (i+1)) - 1;
        for (int j = 0; j < N; j++) A[j] &= t;
        sort(A.begin(), A.end());
        ll cnt = 0;
        for (int j = 0; j < N; j++) {
            B[j] &= t;
            auto it1 = lower_bound(A.begin(), A.end(),  (1 << i) - B[j]);
            auto it2 = lower_bound(A.begin(), A.end(),  (1 << (i+1))- B[j]);
            cnt += distance(it1, it2);
            auto it3 = lower_bound(A.begin(), A.end(),  (3 << i) - B[j]);
            cnt += distance(it3, A.end());
        }
        ans += ((cnt%2) << i);
    }
    cout << ans << endl;
    return 0;
}