#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{

    ll n;
    cin>>n;
    ll arr[n+5]= {0};
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    ll cnt=0;
    ll ans=INT_MAX;
    for(int i=0; i<n; i++)
    {
        cnt=0;
        if(arr[i]%2==0)
        {
            while(arr[i]%2==0)
            {
                cnt++;
                arr[i]/=2;
            }
            ans=min(ans,cnt);
        }
        else
        {
            ans=min(ans,cnt);
        }



    }
    cout<<ans<<endl;



}

