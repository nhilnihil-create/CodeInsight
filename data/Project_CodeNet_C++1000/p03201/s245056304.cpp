#include<bits/stdc++.h>
typedef long long ll;
#define dbg          cout<<"Freak"<<endl;
#define dbgg(i)      cout<<i<<endl;
#define N            1e9+7;
using namespace std;
ll t;
ll arr[200005];
ll p[100];
void po()
{
    ll i,j;
    p[0]=1;
    for(i=1;i<=34;i++)
    {
        p[i]=p[i-1]*2;
        //dbgg(p[i]);
    }
}
int main()
{
    ll a,b=0,c=0,d,e,f,g,i,j;
    cin>>a;
    po();
    map<ll,ll>mp,np;
    for(i=0;i<a;i++){cin>>arr[i];mp[arr[i]]++;np[arr[i]]++;}
    sort(arr,arr+a);
    for(i=0;i<a;i++)
    {
        if(mp[arr[i]]==0)continue;
        mp[arr[i]]--;
        for(j=0;j<34;j++)
        {
            d=p[j]-arr[i];
            //if(arr[i]==3)dbgg(d);
            if(d>0&&mp[d]>0)
            {
                mp[d]--;
                b++;
                break;
            }

        }
    }
    for(i=a-1;i>=0;i--)
    {
        if(np[arr[i]]==0)continue;
        np[arr[i]]--;
        for(j=0;j<34;j++)
        {
            d=p[j]-arr[i];
            if(d>0&&np[d]>0)
            {
                np[d]--;
                c++;
                break;
            }

        }
    }
    cout<<max(b,c)<<endl;
    return 0;
}

