//Code by Mukul Totla
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{   
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n,m,i;
  cin>>n>>m;
  ll arr[m];
  for(i=0; i<m; i++)
    cin>>arr[i];
    if(n>=m)
    {
      cout<<0;
      return 0;
    }
  ll val=n-1;
  sort(arr, arr+m);
  ll prefix[m-1];
  for(i=1; i<m; i++)
  {
    prefix[i-1]=arr[i]-arr[i-1];
  }
  // for(i=0; i<m-1; i++)
  //   cout<<prefix[i]<<" ";
  //   cout<<'\n';
  sort(prefix,prefix+(m-1));
  ll var=m-1-val;
  ll sum=0;
  for(i=0; i<var; i++)
    sum+=prefix[i];
  cout<<sum;

  return 0;
}