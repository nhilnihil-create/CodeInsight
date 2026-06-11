#include<bits/stdc++.h>
using namespace std;

// macro
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long
#define all(v) v.begin(), v.end()

// code starts
int main()
{
  int n;cin>>n;
  vector<int> primes(n+1,0);
  int i,j,k;
  for(i=2;i<=n;i++)
  {
    int left=i;
    for(j=2;j*j<=i;j++)
    {
      while(left%j==0)
      {
        primes[j]++;
        left/=j;
      }
    }
    if(left!=1)primes[left]++;
  }
  int ans=0;
  for(i=2;i<=n;i++)if(primes[i]>=74)ans++;
  for(i=2;i<=n;i++)
  {
    for(j=2;j<=n;j++)
    {
      if(i==j)continue;
      if(primes[i]>=2&&primes[j]>=24)ans++;
      if(primes[i]>=4&&primes[j]>=14)ans++;
    }
  }
  for(i=2;i<=n;i++)
  {
    for(j=2;j<=n;j++)
    {
      for(k=j+1;k<=n;k++)
      {
        if(i==j||i==k||j==k)continue;
        if(primes[i]>=2&&primes[j]>=4&&primes[k]>=4)ans++;
      }
    }
  }
  cout<<ans<<endl;
}
