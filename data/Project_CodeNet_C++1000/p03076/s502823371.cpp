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
    ll T=1,t,n,sum=0,k,i,j;
    // cin>>T;
    while(T--)
    {
        n=5;
        ll a[n],rnd[n],di[n];
        FOR(i,0,n)
        {
            cin>>a[i];
            if(a[i]%10==0)
                rnd[i]=a[i];
            else
                rnd[i] = (10- a[i]%10) + a[i]; 
            sum += rnd[i];
        }
        ll ans = sum;
        FOR(i,0,n)
        {   
            di[i] = sum + a[i]-rnd[i];
            if(ans>di[i])
                ans=di[i];
        }
        cout<<ans<<endl;
    }
}