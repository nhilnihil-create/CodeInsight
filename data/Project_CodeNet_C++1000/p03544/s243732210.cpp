#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  ll n;
  cin >> n;
  ll a[90];
  a[0] = 2; a[1] = 1;
  for(int i=2; i<n+1; ++i) a[i] = a[i-1]+a[i-2];
  cout << a[n] << endl;
}