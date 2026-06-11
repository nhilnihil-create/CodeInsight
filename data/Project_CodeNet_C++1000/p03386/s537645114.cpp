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
  ll a,b,k;
  cin >> a >> b >> k;
  map<ll,ll> mp;
  for(int i = a;i <= a + k - 1;i++)mp[i]++;
  for(int i = b;i >= b - k + 1;i--)mp[i]++;
  for(auto i:mp){
    if(i.first >= a && i.first <= b)cout << i.first << endl;
  }
}