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
  ll k,a,b;
  cin >> k >> a >> b;
  if(k <= a || a >= b - 1)cout << k + 1<< endl;
  else{
    ll res = 0;
    res = a;
    k -= a - 1;
    res += (k / 2) * (b - a);
    if(k % 2 == 1)res++;
    cout << res << endl;
  }
}