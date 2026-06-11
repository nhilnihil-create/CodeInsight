#include<bits/stdc++.h>
using namespace std;

long long gcd(long long x, long long y)
{
    while(1)
    {
        if (x == 0 || y == 0)
        {
            return max(x,y);
        }
        else
        {
            if (x > y)
            {
                x = x % y;
            }
            else
            {
                y = y % x;
            }
        }
    }
}

int main(void)
{
    long long N;
    cin >> N;
    vector<long long> A(N+1);
    for (long long i = 1; i < N+1; i++)
    {
        cin >> A[i];
    }
    vector<long long> L(N+2);
    vector<long long> R(N+2);
    L[0] = 0;
    for (long long i = 1; i < N; i++)
    {
        L[i] = gcd(L[i-1], A[i]);
    }
    R[N+1] = 0;
    for (long long i = N; i > 0; i--)
    {
        R[i] = gcd(R[i+1], A[i]);
    }
    vector<long long> M(N+1);
    M[0] = 0;
    for (long long i = 1; i <N+1; i++)
    {
        M[i] = gcd(L[i-1], R[i+1]);
    }
    sort(M.begin(), M.end());
    cout << M[N] << endl;
}