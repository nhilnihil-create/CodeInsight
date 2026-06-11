#include<bits/stdc++.h>
using namespace std;
#define  mem(a,x) memset(a,x,sizeof(a));
#define  ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define  ll  long long
#define  pi  pair<int,int>
#define  pb  push_back
#define  F   first
#define  S   second
#define  B   begin()
#define  E   end()
const int N=2e5+3;
//string s,p;
//vector<int>v;
//map<int,int>mp;
int main()
{
    ft
    int i,j,k,n,m,l=0,r;
    cin>>n;
    int a[n+1];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<n;i++)
    {
        for(j=n-1;j>=i;j--)
        {
            m=INT_MAX;
            for(k=i;k<=j;k++)
            {
                m=min(m,a[k]);
            }
            l+=m;
            for(k=i;k<=j;k++)
            {
                a[k]-=m;
            }
        }
    }
    cout<<l<<"\n";
    return 0;
}