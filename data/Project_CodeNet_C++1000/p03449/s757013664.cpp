#include<bits/stdc++.h>
using namespace std;
#define ll long long
int pref[110];
int suff[110];

int main()
{
  int n;
  cin >> n;
  int ara[n+10],freak[n+10];
  for(int i=1; i<=n; i++)
  {
      cin >> ara[i];
  }
  for(int i=1; i<=n; i++)
  {
      cin >> freak[i];
  }

  for(int j=1; j<=n; j++)
  {
      pref[j] += pref[j-1] + ara[j] ;
  }
  for(int j=n; j>=1; j--)
  {
      suff[j] += suff[j+1] + freak[j] ;
  }

  int mx = 0;
  for(int i=1; i<=n; i++)
  {
      mx = max(mx,pref[i]+suff[i]);
  }
  cout << mx << endl;


}
