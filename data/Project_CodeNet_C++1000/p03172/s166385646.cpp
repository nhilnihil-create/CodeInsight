#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,k;
    cin>>n>>k;
    vector<ll> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    vector< vector<ll> > v1(n,vector<ll>(k+1));
    for(int i=0;i<n;i++)
    for(int j=0;j<=k;j++)
        v1[i][j]=0;
    for(int i=0;i<=v[n-1];i++)
    {
        v1[n-1][i]=1;
    }
    for(int i=n-2;i>=0;i--)
    {
        vector<int> s(k+1);
        s[0]=v1[i+1][0];
        for(int j=1;j<=k;j++)
            s[j]=(s[j-1]+v1[i+1][j])%1000000007;
        for(int j=0;j<=k;j++)
        {
            int t=s[j];
            if(j>v[i])
            {
                t=(t-s[j-v[i]-1]+1000000007)%1000000007;
            }
            v1[i][j]=t%1000000007;
        }
    }
    cout<<v1[0][k]%1000000007<<endl;
  return 0;
}
