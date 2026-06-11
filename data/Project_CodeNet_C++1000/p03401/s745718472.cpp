#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef long long ll;
ll n;
ll x[100000+5], y[100000+5];
int main(){
  cin >> n;
  for(int i=0 ; i<n ; i++){
    cin >> x[i];
  }
  ll sum = 0;
  for(int i=0 ; i+1<n ; i++){
    y[i] = abs(x[i+1] - x[i]);
    sum += y[i];
  }
  sum += abs(x[n-1])+abs(x[0]);
  
  for(int i=0 ; i<n ; i++){
    ll a = 0;
    if(i) a = x[i-1];
    ll b = x[i];
    ll c = 0;
    if(i != n-1) c = x[i+1];
    ll ans = sum;
    ans -= abs(b-a);
    ans -= abs(c-b);
    ans += abs(a-c);
    cout << ans << endl;
  }
  return 0;
}
