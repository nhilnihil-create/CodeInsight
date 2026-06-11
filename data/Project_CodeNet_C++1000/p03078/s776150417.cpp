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
  ll x,y,z,k;
  cin >> x >> y >> z >> k;
  vector<ll> a(x);
  vector<ll> b(y);
  vector<ll> c(z);
  vector<ll> ab;
  for(int i = 0;i < x;i++)cin >> a[i];
  for(int i = 0;i < y;i++)cin >> b[i];
  for(int i = 0;i < z;i++)cin >> c[i];
  for(int i = 0;i < x;i++){
    for(int j = 0;j < y;j++){
      ab.push_back(a[i] + b[j]);
    }
  }
  sort(ab.rbegin(),ab.rend());
  //for(auto i:ab)cout << i << " ";
  //cout << endl;
  vector<ll> abc;
  ll size = ab.size();
  for(int i = 0;i < min(k,size);i++){
    for(int j = 0;j < z;j++){
      abc.push_back(ab[i] + c[j]);
    }
  }
  sort(abc.rbegin(),abc.rend());
  for(int i = 0;i < k;i++)cout << abc[i] << endl;
}