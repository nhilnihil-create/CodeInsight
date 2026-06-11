#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i,n) for (int i = 1; i <= (int)(n); i++)

int main()
{
  int n;
  cin >> n;
  
  int x[n];
  int tmp[n];
  rep(i,n)
  {
    cin >> x[i];
    tmp[i] = x[i];
  }
  sort(tmp,tmp+n);
 
  int mid1 = tmp[n/2-1];
  int mid2 = tmp[n/2];
  int ans[n];
  rep(i,n)
  {
    if(x[i] <= mid1) ans[i] = mid2;
    else if(x[i] >= mid2) ans[i] = mid1;
  }
  
  rep(i,n) cout << ans[i] << endl;
}