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
int n;
int checkZero(vi &h){
  int cnt = 0;
  int ans = 0;
  rep(i, n){
    if(h[i]){
      cnt++;
    }else{
      if(cnt) ans++;
      cnt = 0;
    }
  }
  if(cnt) ans++;
  return ans;
}
int main(){
  cin >> n;
  vi h(n);
  rep(i, n) cin >> h[i];
  int ans = 0;
  int cnt = 0;
  while(true){
    int a = checkZero(h);
    if(!a) break;
    rep(i, n){
      if(h[i]) h[i]--;
    }
    ans += a;
  }
  cout << ans << endl;
}