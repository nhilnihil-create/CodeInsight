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
  ll mod = pow(10,9) + 7;
  int n = 0;
  cin >> n;
  string str;
  cin >> str;
  ll res = 0;
  res = 1;
  for(int i = 0;i <= 25;i++){
    ll count = 0;
    for(int j = 0;j <= n - 1;j++){
      if(str[j] == 'a' + i)count++;
    }
    res = (res * (count + 1)) % mod;
  }
  res--;
  if(res < 0)res += mod;
  cout << res << endl;
  return 0;
}