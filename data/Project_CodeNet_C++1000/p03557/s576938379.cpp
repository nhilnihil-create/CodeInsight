#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int N;
    cin >> N;
    vector<int> A(N),B(N),C(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> C[i];
    }
    sort(A.begin(), A.end());
    sort(C.begin(), C.end());
    
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        int x = B[i];
        auto sum1 = lower_bound(A.begin(), A.end(), x) - A.begin();
        auto sum2 = N - (upper_bound(C.begin(), C.begin()+N, x) - C.begin());
        ans += sum1 * sum2;
    }
    cout << ans << endl;
}