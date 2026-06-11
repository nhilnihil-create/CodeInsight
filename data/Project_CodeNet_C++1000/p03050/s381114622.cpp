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
int main(){
  ll n;
  cin >> n;
  ll res = 0;
  for(ll i = 2;i <= sqrt(n);i++){
    if(n % i == 0){
      ll j = 0;
      j = n / i;
      if(n / (i-1) == n % (i-1))res += i-1;
      if(n / (j-1) == n % (j-1))res += j-1;
    } 
  }
  if(n > 1)if(n / (n-1) == n % (n-1))res += n-1;
  cout << res << endl;
}