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
  ll n,m;
  cin >> n >> m;
  map<ll,ll> mp;
  ll count = 0;
  for(int i = 0;i < n;i++){
    ll k = 0;
    cin >> k;
    for(int j = 0;j < k;j++){
      ll in = 0;
      cin >> in;
      mp[in]++;
    }
  }
  for(auto i:mp){
    if(i.second == n)count++;
  }
  cout << count << endl;
}