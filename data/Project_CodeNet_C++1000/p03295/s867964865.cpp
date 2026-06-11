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
  vector<pair<ll,ll>> a(m);
  for(int i = 0;i < m;i++){
    ll ina,inb;
    cin >> ina >> inb;
    a[i] = make_pair(inb,ina);
  }
  sort(a.begin(),a.end());
  ll mae = 0;
  ll res = 0;
  for(int i = 0;i < m;i++){
    if(mae >= a[i].second)continue;
    else{
      mae = a[i].first - 1;
      res++;
    }
    //cout << i << " " << mae << endl;
  }
  cout << res << endl;
}