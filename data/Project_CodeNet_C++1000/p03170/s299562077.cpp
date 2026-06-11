#include<iostream>
#include<vector>
#include<cstdlib>
#include<algorithm>
#include<climits>
#include<queue>
#include<stack>
#include<cmath>
#include<iterator>
typedef long long ll;
using namespace std;
#define rep(x, y)   for (ll i = x; i <= y; i ++)
#define repi(x, y)  for (ll i = x; i >= y; i --)
priority_queue< ll > cancel;
ll arr[200005];
ll brr[200005];
bool dp[200005];
int main()
{
    ll test=1;
    // cin>>test;
    for(ll z=0;z<test;z++)
    {
        ll n,k;
        cin>>n>>k;
        for(ll i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        sort(arr,arr+n);
        for(ll i=0;i<arr[0];i++)
        {
            dp[i]=false;
        }
        for(ll i=arr[0];i<=k;i++)
        {
            bool flag=false;
            for(ll j=0;(arr[j]<=i && j<n);j++)
            {
                // if(i==5)
                // {
                //     cout<<!(dp[i-arr[j]])<<" "<<i-arr[j]<<endl;
                // }
                flag|=!(dp[i-arr[j]]);
            }
            dp[i]=flag;
        }  
        
        if(dp[k]==true)
        {
            cout<<"First"<<endl;
        }
        else
        {
            cout<<"Second"<<endl;
        }
         
    }
}