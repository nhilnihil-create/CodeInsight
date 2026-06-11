#include <iostream> // cout, endl, cin
#include <cmath> //sqrt pow
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
 
#define rep(i,n) for(int i = 0; i < n; i++)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define mod 1000000007
using ll = long long;
using namespace std;
bool check753(ll n){
  int shichi = 0, go = 0, san = 0;
  while(n){
    switch(n % 10){
      case 3: san++; break;
      case 5: go++; break;
      case 7: shichi++; break;
    }
    n /= 10;
  }
  return san > 0 && go > 0 && shichi > 0;
}
int main(){
  int n;
  cin >> n;
  vector<ll> shichigosan{3,5,7};
  int cnt = 3, before = 0;
  while(shichigosan[cnt - 1] < n){
    for(int i = before; i < cnt; i++){
      ll num = shichigosan[i] * 10;
      shichigosan.push_back(num + 3);
      shichigosan.push_back(num + 5);
      shichigosan.push_back(num + 7);
    }
    before = cnt;
    cnt *= 3;
  }
  int ans = 0;
  for(ll i : shichigosan){
    if(i > n) break;
    if(check753(i)){
      ans++;
    }
  }
  cout << ans << endl;
}