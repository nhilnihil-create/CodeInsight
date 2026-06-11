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
  string in;
  cin >> n >> in;
  string a = in.substr(0,n);
  string b = in.substr(n,n);
  reverse(b.begin(),b.end());
  //cout << a << " " << b << endl;
  
  map<pair<string,string>,ll> mp;
  for(int i = 0; i < (1<<n); i++){//2のa乗回繰り返す(0 ~ 2^a- 1)
    string red;
    string blue;
    for(int j = 0;j < n;j++){
      if(i & (1<<j))red += a[j];
      else blue += a[j];
    }
    mp[make_pair(red,blue)]++;
  }
  
  ll res = 0;
  for(int i = 0;i < (1<<n);i++){
    string red;
    string blue;
    for(int j = 0;j < n;j++){
      if(i & (1<<j))red += b[j];
      else blue += b[j];
    }
    res += mp[make_pair(blue,red)];
    //cout << blue << " " << red << " " << mp[make_pair(blue,red)] << endl;
  }
  cout << res << endl;
}