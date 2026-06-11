#include<bits/stdc++.h>
using namespace std;

// macro
#define rep(i,n) for(i=0;i<n;i++)
#define ll long long
#define all(v) v.begin(), v.end()

// code starts
int main()
{
  int n;
  cin >> n;
  vector<ll> a(n);
  vector<ll> b(n);
  int i;
  rep(i,n) cin >> a[i];
  rep(i,n) cin >> b[i];
  ll add_a = 0;
  ll add_b = 0;
  rep(i,n-1)
  {
    if(a[i] == b[i]) continue;
    else if(a[i] > b[i])
    {
      if(add_b+b[i] >= a[i])
      {
        add_b -= (a[i]-b[i]);
      }
      else
      {
        b[i] += add_b;
        add_b = 0;
        add_a += (a[i]-b[i])*2;
      }
    }
    else
    {
      if(add_a >= b[i]-a[i])
      {
        add_a -= (b[i]-a[i]);
        if((b[i]-a[i])%2 == 1)
        {
          add_a--;
          if(add_b > 0)
          {
            add_b--;
          }
          else
          {
            add_a += 2;
          }
        }
      }
      else
      {
        a[i] += add_a;
        add_a = 0;
        ll dis = abs(a[i]-b[i]);
        if(dis%2 == 1)
        {
          add_b += (dis+1)/2;
          add_b--;
        }
        else
        {
          add_b += dis/2;
        }
      }
    }
  }
  if(a[n-1]+add_a <= b[n-1]+add_b) cout << "Yes" << endl;
  else cout << "No" << endl;

}

