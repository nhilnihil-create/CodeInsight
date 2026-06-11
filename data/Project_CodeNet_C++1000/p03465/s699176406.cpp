#include <bits/stdc++.h>
using namespace std;
#define ll long long //pi        3.14159265358979323846
int main() {

ll n,s=0;
cin>>n;
vector<ll> v(n);
for(int i=0;i<n;i++)
{
    cin>>v[i];
    s=s+v[i];
}
bitset<10000000> dp;
dp[0]=1;
for(int i=0;i<n;i++)
{
    dp=dp|(dp<<v[i]);
}
ll i=(s+1)/2;
while(dp[i]==0)
{
    i++;
}
cout<<i<<endl;

	return 0;
} 