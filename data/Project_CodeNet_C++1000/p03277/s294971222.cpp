#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=100005;
ll tree[3*N];
ll prev(ll x)
{
    return (x&(x-1));
}
ll next(ll x)
{
    return 2*x-prev(x);
}
void update(ll ind, ll diff)
{
    while(ind<=2*N)
    {
        tree[ind]+=diff;
        ind=next(ind);
    }
}
ll get(ll ind1, ll ind2)
{
    ll ans=0;
    while(ind2)
    {
        ans+=tree[ind2];
        ind2=prev(ind2);
    }
    ind1--;
    while(ind1)
    {
        ans-=tree[ind1];
        ind1=prev(ind1);
    }
    return ans;
}
long long a[N],b[N],sum[N];
int main()
{
    #define int long long
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    if(n==1)
    {
        cout<<a[0]<<endl;
        return 0;
    }
    int ans;
    int low=0, high=1e9;
    while(low<=high)
    {
        int mid=(low+high)/2;
        for(int i=0;i<n;i++)
            if(a[i]>=mid)
                b[i]=1;
            else
                b[i]=-1;
        sum[0]=b[0];
        int neg=0,pos=0;
        if(sum[0]<0)
            neg++;
        else
            pos++;
        for(int i=1;i<n;i++)
        {
            sum[i]=sum[i-1]+b[i];
            if(sum[i]<0)
                neg++;
            else
                pos++;
        }
        long long tot=0;
        update(sum[0]+N,1);
        for(int i=1;i<n;i++)
        {
            tot+=get(1,sum[i]+N);
            pos+=get(1,sum[i]+N);
            neg+=i-get(1,sum[i]+N);
            update(sum[i]+N,1);
        }
        for(int i=0;i<n;i++)
            update(sum[i]+N,-1);
        if(pos>=neg)
        {
            ans=mid;
            low=mid+1;
        }
        else
            high=mid-1;
        continue;
        long long mn=1LL*n*(n-1)/2;
        mn=(mn+1)/2;
        if(tot>=mn)
        {
            ans=mid;
            low=mid+1;
        }
        else
            high=mid-1;
    }
    cout<<ans<<endl;
    return 0;
}
