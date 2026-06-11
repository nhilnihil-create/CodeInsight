#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll GCD(ll a, ll b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}

int main()
{
    ll N;
    cin >> N;
    vector<ll> A(N,0);
    for(ll i=0;i<N;i++)
    {
        cin>>A[i];
    }
    ll res=A[0];
    for(ll i=0;i<N;i++)
    {
        res=GCD(A[i],res);
    }
    cout<<res; 
    return 0;
}