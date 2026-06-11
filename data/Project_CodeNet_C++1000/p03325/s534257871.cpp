#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{

  ll n;
  cin >> n;
  ll cnt = 0;
  ll mx = 0;
  vector<ll>vec;
  bool mrk = 0;
  for(int i=0; i<n; i++)
  {
     ll x;
      cin >> x;

    if(x%2==0)
    {
        ll v = x;
        mrk = 1;
    cnt = 0;
       while(x%2==0)
       {
           x/=2;cnt++;
       }
       //cout << v << " " << cnt << endl;
       mx+=cnt;

    }
  }

  if(mrk)cout << mx << endl;
  else cout << 0 << endl;


      }
