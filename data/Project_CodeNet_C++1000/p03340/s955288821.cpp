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
#include <bitset>
using namespace std;
typedef long long ll;
int main(){
  ll n = 0;
  cin >> n;
  vector<vector<ll>> bit(n,vector<ll>(20));
  for(int i = 0;i < n;i++){
    ll in = 0;
    cin >> in;
    for(int j = 19;j >= 0;j--){
      bit[i][j] = in / pow(2,j);
      in -= bit[i][j] * pow(2,j);
    }
  }
  ll l = 0;
  ll res = 0;
  ll r = 1;
  vector<ll> now(20);
  for(int i = 0;i < 20;i++)now[i] = bit[0][i];
  //cout << "a" << endl;
  for(int i = 0;i < n - 1;i++){
    while(1){
      if(r >= n)break;
      bool ok = true;
      for(int j = 0;j < 20;j++){
        if(now[j] + bit[r][j] > 1)ok = false;
      }
      //cout << i << " b" << endl;
      if(!ok)break;
      for(int j = 0;j < 20;j++)now[j] += bit[r][j];
      r++;
    }
    //cout << i << " " << r << endl;
    res += r - i;
    for(int j = 0;j < 20;j++)now[j] -= bit[i][j];
  }
  res++;
  cout << res << endl;
}