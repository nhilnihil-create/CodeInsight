#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<long long> A(N);
    vector<long long> B(N);
    vector<long long> C(N);
    for (int i=0; i<N; i++) cin >> A[i];
    for (int i=0; i<N; i++) cin >> B[i];
    for (int i=0; i<N; i++) cin >> C[i];
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());

    long long ans = 0;
    for (int i=0 ; i<N; i++)
    {
        long long target_B = B[i];
        long int A_upper = lower_bound(A.begin(), A.end(), target_B) - A.begin();
        long int C_lower = lower_bound(C.begin(), C.end(), target_B +1) - C.begin();
        ans += A_upper * (N - C_lower);
    }

    cout << ans << endl;
}
