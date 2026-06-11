#include<bits/stdc++.h>

using namespace std;

int main()
{
    int N; cin >> N;
    vector<long long> A(N), B(N), C(N);

    for(int i=0; i<N; ++i) cin >> A[i];
    for(int i=0; i<N; ++i) cin >> B[i];
    for(int i=0; i<N; ++i) cin >> C[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());

    vector<long long> BC(N + 1, 0);
    for(int i=N-1; i>=0; --i)
    {
        auto itr = upper_bound(C.begin(), C.end(), B[i]);
        BC[i] = BC[i+1] + (C.end() - itr);
    }

    long long ans = 0;
    for(int i=0; i<N; ++i)
    {
        auto itr = upper_bound(B.begin(), B.end(), A[i]);
        
        if(itr != B.end()) ans += BC[itr - B.begin()];
    }

    cout << ans << endl;
}