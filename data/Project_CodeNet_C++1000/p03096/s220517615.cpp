#include <bits/stdc++.h>
using namespace std;

const int mod = (int) 1e9 + 7;

int A[200005];
long long dpPos[200005], dpCol[200005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    int N;
    cin >> N;

    for(int i=1; i<=N; i++)
        cin >> A[i];
    
    dpPos[0] = 1;
    long long ans = 0;

    for(int i=1; i<=N; i++)
    {
        dpPos[i] = dpPos[i-1];

        if(A[i] != A[i+1])
        {
            dpPos[i] = (dpPos[i] + dpCol[ A[i] ]) % mod;
            dpCol[ A[i] ] = (dpCol[ A[i] ] + dpPos[i-1]) % mod;
        }
    }

    cout << dpPos[N] << "\n";
    return 0;
}
