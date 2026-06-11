#include<bits/stdc++.h>
#include<string.h>
#define pb push_back
#define all(v) v.rbegin(),v.rend()
#define see(x) cout<<#x<<" : "<<(x)<<endl;
#define ya cout<<"yes"<<endl;
#define no cout<<"no"<<endl;
#define ff first
#define sc second
typedef long long ll;
using namespace std;

int main()
{
    int n,i,j,val=0,cost=0,ans=0;
    cin>>n;
    vector<int>v,c;
    for(i=0;i<n;i++)
    {
        cin>>j;
        v.pb(j);
    }
    for(i=0;i<n;i++)
    {
        cin>>j;
        c.pb(j);
    }
    for(i=0;i<n;i++)
    {
        if(v[i]>c[i])
            cost+=(v[i]-c[i]);
    }
    cout<<max(0,cost)<<endl;
    return 0;
}
