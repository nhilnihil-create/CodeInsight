#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <climits>
#include <iomanip>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){
  if(a % b == 0)return b;
  else{
     return(gcd(b,a% b));
  }
}
int main(){
  ll n,x;
  cin >> n >> x;
  vector<ll> a(n);
  for(int i = 0;i < n;i++){
    ll num = 0;
    cin >> num;
    a[i] = abs(x - num);
  }
  ll res = 0;
  res = a[0];
  for(int i = 1;i < n;i++)res = gcd(res,a[i]);
  cout << res << endl;
}