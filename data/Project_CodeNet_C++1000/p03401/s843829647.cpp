#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll pref[101000];
ll suff[101000];
ll ara[101000];
int main()
{
  ll n , d , rem;
  cin >> n;
 // int ara[n+10];
  ara[n+1] = 0 ;
  ara[0] = 0;
  for(int i=1; i<=n; i++)
  {
      cin >> ara[i];
      
  }
  for(int i=1; i<=n; i++)
  {
      pref[i] = pref[i-1]+abs(ara[i]-ara[i-1]);
  }

  for(int i=n; i>=1; i--)
  {

      suff[i] = suff[i+1]+abs(ara[i]-ara[i+1]);
  }


  for(int i=1; i<=n; i++)
  {
      ll lft = pref[i-1],rgt = suff[i+1],mid = abs(ara[i-1]-ara[i+1]);
      //cout << pref[i-1] << endl;
      cout << lft + rgt + mid << endl;
  }




  }
