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
        string st,a="",b="";
        cin>>st;
        FOR(i,0,st.length())
        {
            if(i%2==0){
                a += '0';
                b += '1';
            }
            else{
                a += '1';
                b += '0';
            }
        }
        ll ans=0,res=0;
        FOR(i,0,st.length())
        {
            ans += (st[i]!=a[i]);
            res += (st[i]!=b[i]);
        }
        cout<<min(ans,res)<<endl;
    }
}