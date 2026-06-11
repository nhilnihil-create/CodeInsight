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
  vector<pair<ll,pair<ll,ll>>> d(n);
  for(int i = 0;i < n;i++){
    cin >> d[i].second.first >> d[i].second.second;
    d[i].first = d[i].second.first + d[i].second.second;
  }
  sort(d.rbegin(),d.rend());
  ll t = 0;
  ll a = 0;
  for(int i = 0;i < n;i++){
    if(i % 2 == 0)t += d[i].second.first;
    else a += d[i].second.second;
  }
  cout << t - a << endl;
}