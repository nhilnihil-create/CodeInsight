#include<bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define ll long long
int main()
{
    ll n,i,j,k,l,m;
    cin>>n;
    k=0;
    l=INT_MIN;
    for(i=0;i<n;i++)
    {
        cin>>j;
        k+=j;
        if(j>l){l=j;}
    }
    k-=l;
    k+=(l/2);
    cout<<k<<endl;
    return 0;
}
