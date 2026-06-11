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
    ll T=1,t,a,b,q,k,i,j;
    // cin>>T;
    while(T--)
    {
        cin>>a>>b>>t;
        if(t<a){
            cout<<0<<endl;
            break;
        }
        k=a; j=b; i=2;
        while(k<=t)
        {
            k = (i*a);
            if(k>t)break;
            j += b;
            i++;
        }
        cout<<j<<endl;
    }
}