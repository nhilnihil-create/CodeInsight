#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int N, Z, W;
    cin >> N >> Z >> W;
    int A[N+3];
    for(int i = 0; i < N; ++i) cin >> A[i];

    if(N == 1) cout << abs(A[0] - W) << endl;
    else cout << max(abs(A[N-1] - W), abs(A[N-2] - A[N-1]));
    return 0;
}