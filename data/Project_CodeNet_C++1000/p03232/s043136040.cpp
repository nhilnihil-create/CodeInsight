#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int M=1e9+7;
const int N=1e5+5;
ll n,a[N],x=1,b[N],res=0;

ll quick_pow(ll a,ll b)
{
    ll res=1;
    while(b)
    {
        if(b&1)
        {
            res=(res%M*a%M)%M;
        }
        a=(a%M*a%M)%M;
        b>>=1;
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        x=(x%M*i%M)%M;
        b[i]=quick_pow(i,M-2);
        cin >> a[i];
    }
    for(int i=1;i<=n;i++)
        b[i]=(b[i]%M+b[i-1]%M)%M;
    for(int i=1;i<=n;i++)
        res=(res%M+a[i]*(b[i]+b[n-i+1]-1)%M)%M;
    cout << (res%M*x%M)%M << endl;
    return 0;
}
