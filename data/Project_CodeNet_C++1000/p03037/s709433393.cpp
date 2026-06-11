#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  ll n,m;
  cin >> n >> m;
  
  ll l[m],r[m];
  rep(i,m) cin >> l[i] >> r[i];
  
  ll left = 0, right = n;
  rep(i,m)
  {
    if(l[i] > left)
    {
      left = l[i];
    }
    if(r[i] < right){
      right = r[i];
    }
  }
  
  if(right - left < 0)
  {
    cout << 0 << endl;
  }else{
    cout << right - left + 1 << endl;
  }
  
}