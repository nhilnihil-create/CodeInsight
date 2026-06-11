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
  ll n = 0;
  cin >> n;
  vector<ll> m(n);
  map<ll,ll> count;
  for(int i = 0;i < n;i++){
    cin >> m[i];
    if(i != 0)m[i] += m[i - 1];
    count[m[i]]++;
  }
  ll res = 0;
  vector<ll> fac(100000);
  for(auto i:count){
    res += i.second * (i.second - 1) / 2;
  }
  res += count[0];
  cout << res << endl;
}