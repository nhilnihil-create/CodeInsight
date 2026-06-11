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
  map<char,ll> mp;
  for(int i = 0;i < n;i++){
    char in;
    cin >> in;
    mp[in]++;
  }
  if(mp.size() == 3)cout << "Three" << endl;
  else cout << "Four" << endl;
}