#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define M 1000000007
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define f first
#define s second
#define b begin
#define e end
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for(i=a;i<b;i++)
#define RFOR(i,a,b) for(i=a;i>=b;i--)
#define all(x) x.begin(),x.end()
#define itfr(it,x) for(it=x.begin();it!=x.end();it++)
#define flash ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

int main()
{
    flash;
    //sieve();
    ll T=1,t,n,m,q,k,i,j;
    // cin>>T;
    while(T--)
    {
        cin>>n;
        ll a[n];
        FOR(i,0,n)  cin>>a[i];
        ll pr[n],suf[n],gd[n];
        pr[0] = a[0];
        suf[n-1] = a[n-1];
        FOR(i,1,n)
            pr[i] = __gcd(pr[i-1],a[i]);
        RFOR(i,n-2,0)
            suf[i] = __gcd(suf[i+1],a[i]);
        gd[0] = suf[1];
        gd[n-1] = pr[n-2];
        FOR(i,1,n-1)
            gd[i] = __gcd(pr[i-1],suf[i+1]);
        sort(gd,gd+n);
        cout<<gd[n-1]<<endl;
    }
}