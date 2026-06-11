#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <climits>
#include <iomanip>
using namespace std;
typedef long long ll;
int main(){
  ll n = 0;
  cin >> n;
  vector<ll> count(n);
  ll allb = 0;
  for(int i = 0;i <= n - 1;i++){
    ll a = 0;
    ll b = 0;
    cin >> a >> b;
    count[i] = a + b;
    allb += b;
  }
  sort(count.begin(),count.end());
  ll res = 0;
  /*ll akaisuu = 0;
  akaisuu = n / 2;
  if(n % 2 == 1)akaisuu++;
  cout << akaisuu << endl;*/
  for(int i = n - 1;i >= 0;i--){
    if((n - 1 - i) % 2 == 0)res += count[i];
  }
  //cout << res << endl;
  res -= allb;
  cout << res << endl;
  return 0;
}