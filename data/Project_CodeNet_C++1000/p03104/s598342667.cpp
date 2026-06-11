/**In the name of ALLAH*/

#include<bits/stdc++.h>

using namespace std;
#define pri(n)          printf("%d\n",n)
#define prll(n)         printf("%lld\n",n)
#define prd(n)          printf("%lf\n",n)
#define scll(n)         scanf("%lld",&n)
#define sci(n)          scanf("%d",&n)
#define scd(n)          scanf("%lf",&n)
#define pi              acos(-1)
#define ll              long long
#define pb              push_back
#define vsort(v)        sort(v.begin(),v.end())
#define asort(n)        sort(ar,ar+n)
#define for1(i,n)       for(i=1;i<=n;i++)
#define for0(i,n)       for(i=0;i<n;i++)
#define mod             1000000007
#define watch(x)        cout << (#x) << " is " << (x) <<"\n";
#define yes             cout<<"YES\n"
#define no              cout<<"NO\n"
#define LIMIT           100000 /**upto 10^8*/

ll xorr(ll n)
{
    if(n%4==0) return n;
    else if(n%4==1) return 1;
    else if(n%4==2) return n+1;
    else return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);/**Dont't use scanf of printf*/
    ll t,i,pro,x,k,j,a,b,cnt,q,sum,index,r,n;
    cin>>a>>b;
    if(a<=1) a==0;
    else a--;
    cout<<(xorr(b)^xorr(a))<<endl;



    return 0;
}