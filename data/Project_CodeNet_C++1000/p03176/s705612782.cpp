#include<bits/stdc++.h>
using namespace std;
long long MOD=(long long)(1e9+7);
vector<int> graph[(int)(1e5+7)];


int main()
{
int n;
cin>>n;
vector<long long> h(n),a(n);
int base=1;
while(base<=n)
base*=2;

for(int i=0;i<n;i++)
{
cin>>h[i];
}
for(int i=0;i<n;i++)
{
cin>>a[i];
}
//sorted heights
vector<long long> tree(2*base);

vector<long long > dp((long long)(2e5+8),0);
//n^2
//optimise to nlogn
int pos;
 long long ans=0;
dp[0]=a[0];
for(int i=0;i<n;i++)
{
long long best=0;
int ind=base+h[i];
//max of dp[i] for i in range (0,h[i]);
while(ind>1)
{
    if(ind%2==1)
    {
        best=max(best,tree[ind-1]);
    }
    ind/=2;
}
dp[h[i]]=best+a[i];
//update dp[i]
for(int j=base+h[i];j>=1;j/=2)
{
    tree[j]=max(tree[j],dp[h[i]]);
}

}


for(int i=0;i<n;i++)
{
    ans=max(ans,dp[h[i]]);
}
cout<<ans<<endl;
}