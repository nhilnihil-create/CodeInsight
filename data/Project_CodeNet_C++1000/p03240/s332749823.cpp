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
int main(){
  int n;
  cin >> n;
  vi x(n), y(n), h(n);
  rep(i, n) cin >> x[i] >> y[i] >> h[i];
  rep(i, n){
    if(h[i] > 0){
      swap(h[0], h[i]);
      swap(x[0], x[i]);
      swap(y[0], y[i]);
      break;
    }
  }
  rep(width, 100 + 1){
    rep(height, 100 + 1){
      int high = h[0] + abs(x[0] - width) + abs(y[0] - height);
      bool ok = true;
      for(int i = 1; i < n; i++){
        if(h[i] != max(high - abs(x[i] - width) - abs(y[i] - height), 0)){
          ok = false;
          break;
        }
      }
      if(ok){
        cout << width << " " << height << " " << high << endl;
        return 0;
      }
    }
  }
}