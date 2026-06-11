#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int N;
    cin >> N;
    vector<ll> A(N), B(N);
    ll sum = 0;
    ll remain = 1e10;
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
        sum += A[i];
        if (A[i] > B[i]) {
            remain = min(remain, B[i]);
        }
    }
    if (remain == 1e10) cout << 0 << endl;
    else cout << sum-remain << endl;
    return 0;
}