#include<bits/stdc++.h>
#define ll long long int

using namespace std;

ll find(ll a[],int n)
{
  ll c[n+1][n+1];
  ll sums[n+1][n+1];
  for(int i = 1; i<=n; i++)
  {
    ll s = 0;
    for(int j = i; j<=n; j++)
    {
      s+=a[j];
      sums[i][j] = s;
    }
  }

  for(int s = 0; s<n; s++)
  {
    for(int i = 1,j = i+s; i<=n && j<=n; i++,j++)
    {
        if(i==j)
            c[i][j] = 0;
        else if(j==i+1)
            c[i][j] = sums[i][j];
        else
        {
            c[i][j] = INT64_MAX;
            for(int k = i; k<j; k++)
            {
                ll temp = c[i][k] + c[k+1][j] + sums[i][k]+sums[k+1][j];
                c[i][j] = min(c[i][j],temp);
            }
        }
    }
  }
  return c[1][n];
}

int main()
{
  int n;
  cin>>n;
  ll a[n+1];
  for(int i = 1; i<=n; i++)
    cin>>a[i];
  cout<<find(a,n);
  return 0;
}
