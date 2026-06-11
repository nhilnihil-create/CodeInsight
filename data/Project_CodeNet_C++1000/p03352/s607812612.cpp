#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <cmath>
#include <limits>
using namespace std;
using ll = long long;

ll mypow(ll x, ll n) { //x^nの計算
  ll res = 1;
  while (n > 0) {
    if (n & 1){
      res *= x;  // n の最下位bitが 1 ならば x^(2^i) をかける
    }
    x *= x;
    n >>= 1;  // n を1bit 左にずらす
  }
  return res;
}

int main(){
  int X;
  cin >> X;
  vector<bool> num(1000,false);
  num[1]=true;
  for(int i=2;i<=1000;i++){
    int count=2;
    while(mypow(i,count)<=1000){
      num[mypow(i,count)]=true;
      count++;
    }
  }
  for(int i=X;i>=1;i--){
    if(num[i]){
      cout << i << endl;
      return 0;
    }
  }
}