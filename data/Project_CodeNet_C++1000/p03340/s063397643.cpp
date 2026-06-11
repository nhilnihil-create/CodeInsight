#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct data
{
    ll val[32];
    ll ind[32];
    data()
    {
        ;
    }
};
ll a[200009];
data arr[200009];
vector<pair<ll,ll> > v;
ll sol(ll n)
{

    return (n*(n+1))/2;
}
int main()
{
    ll i,j,n,x,k,y,lo,hi;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    if(n==1)
    {
        cout<<1<<endl;
        return 0;
    }
    data p;
    lo = hi = 0;
    for(i=0;i<n;i++)
    {
        j = 0;
        x = a[i];
        while(a[i]!=0)
        {
            arr[i].val[j] = a[i]%2;
            a[i] = a[i]/2;
            j++;
        }
        a[i] = x;
    }

    for(i=0;i<32;i++)
    {
        p.val[i] = arr[0].val[i];
        p.ind[i] = 0;
    }
    ll ans= 0;
    for(i=1;i<n;i++)
    {
        /*for(j=31;j>=0;j--)
            cout<<p.val[j];
        cout<<endl;
        for(j=31;j>=0;j--)
            cout<<arr[i].val[j];
        cout<<"val i =  "<<a[i]<<endl;*/
        hi = i;
        //cout<<lo<<" "<<hi<<" "<<ans<<endl;
        x = -1;
        for(j=0;j<32;j++)
        {
            if(p.val[j]==1 && arr[i].val[j]==1)
            {

                x = max(x,p.ind[j]);
            }
        }
        //cout<<"x = "<<x<<endl;
        if(x!=-1)
        {
            //cout<<" ans = "<<ans<< " "<<sol(hi-lo)<<endl;
            v.push_back(make_pair(lo,hi-1));
            //cout<<"now ans = "<<ans<<endl;
            lo = x+1;
            for(j=0;j<32;j++)
            {
                if(p.ind[j]<=x)
                {
                    p.val[j] = 0;
                    p.ind[j] = 0;
                }
            }
        }
        /*cout<<"After"<<endl;
        for(j=31;j>=0;j--)
            cout<<p.val[j];
        cout<<endl;
        /*for(j=31;j>=0;j--)
            cout<<p.ind[j];
        cout<<"ind "<<endl;*/
        for(j=0;j<32;j++)
        {
            if(arr[i].val[j]==1)
            {
                p.val[j] = 1;
                p.ind[j] = i;
            }

        }

    }
    //cout<<lo<<" "<<hi<<" "<<ans<<endl;
    //ans+= sol(hi-lo+1);
    v.push_back(make_pair(lo,hi));
    for(j=1;j<v.size();j++)
    {
        if(v[j].first<=v[j-1].second)
        {
            ans-= sol(v[j-1].second-v[j].first+1);
        }
    }
    //cout<<ans<<endl;
    for(j=0;j<v.size();j++)
    {
        ans+= sol(v[j].second-v[j].first+1);
    }

    cout<<ans<<endl;


}
