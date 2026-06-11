#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  int n;
  cin >> n;
  int d,x;
  cin >> d >> x;
  
  int a[n];
  rep(i,n) cin >> a[i];
  
  int ans = 0;
  rep(i,n){
    int day = 1;
    while(day <= d){
      ans++;
      day += a[i];
    }
  }
  
  cout << ans + x << endl;
      
}