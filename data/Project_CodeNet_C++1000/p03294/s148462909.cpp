/**Author:Sagor*/

#include<bits/stdc++.h>
#include<numeric>

using namespace std;
#define pri(n)          printf("%d\n",n)
#define prll(n)         printf("%lld\n",n)
#define prd(n)          printf("%lf\n",n)
#define scll(n)         scanf("%lld",&n)
#define sci(n)          scanf("%d",&n)
#define scd(n)          scanf("%lf",&n)
#define pi              acos(-1)//inbuilt M_PI
#define ll              long long
#define pb              push_back
#define vsort(v)        sort(v.begin(),v.end())
#define asort(n)        sort(ar,ar+n)
#define yes             cout<<"Yes\n"
#define no              cout<<"No\n"
#define for1(i,n)       for(i=1;i<=n;i++)
#define for0(i,n)       for(i=0;i<n;i++)
#define mod             1000000007
#define watch(x)        cout << (#x) << " is " << (x) <<"\n";

/** for print with quote \"hello world\"
    1LL is used to convert into long long*/


int main()
{
    /*freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);*/
    /**ios_base::sync_with_stdio(false);
    cin.tie(NULL);/**Dont't use scanf of printf*/
    ll n,sum=0,i,a;
    cin>>n;
    for0(i,n){
        cin>>a;
        sum+=(a-1);
    }
    cout<<sum<<endl;


    return 0;
}