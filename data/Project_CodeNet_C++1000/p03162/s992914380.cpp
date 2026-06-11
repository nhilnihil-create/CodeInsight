#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll N;
    cin>>N;
    ll a[N],b[N],c[N],A[N],B[N],C[N];
    for(ll i=0;i<N;i++)
    {
        cin>>a[i]>>b[i]>>c[i];
    }
    A[0]=a[0]; B[0]=b[0]; C[0]=c[0];
    for(ll i=1;i<N;i++)
    {
        A[i] = a[i] + max(C[i-1],B[i-1]);
        B[i] = b[i] + max(A[i-1],C[i-1]);
        C[i] = c[i] + max(A[i-1],B[i-1]);
    }
    ll maxm=max(A[N-1],B[N-1]);
    maxm=max(maxm,C[N-1]);
    cout<<maxm;
}