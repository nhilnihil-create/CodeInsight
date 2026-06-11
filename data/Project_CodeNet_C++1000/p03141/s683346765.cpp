#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int64_t> A(n), B(n);
    vector<array<int64_t, 2>> S(n);
    for (int i = 0; i < n; i++){
        cin >> A[i] >> B[i];
        S[i][0] = A[i] + B[i];
        S[i][1] = i;
    }

    sort(S.begin(), S.end(), greater<array<int64_t, 2>>());
    int64_t ans = 0;
    for (int i = 0; i < n; i++){
        if (i % 2 == 0)
            ans += A[S[i][1]];
        else
            ans -= B[S[i][1]];
    }

    cout << ans << endl;
}