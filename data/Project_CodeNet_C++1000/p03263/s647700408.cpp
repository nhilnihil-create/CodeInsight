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
#include <deque> // dequef
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
 
#define rep(i,n) for(int i = 0; i < n; i++)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define all(a) (a).begin(), (a).end()
#define mod 1000000007
using ll = long long;
using namespace std;
int main(){
  int h,w;
  cin >> h >> w;
  vvi a(h, vi(w));
  rep(i, h){
    rep(j, w) cin >> a[i][j];
  }
  vvi ans;
  rep(i, h){
    rep(j, w - 1){
      if(a[i][j] & 1){
        a[i][j]--;
        a[i][j + 1]++;
        ans.push_back({i, j, i, j + 1});
      }
    }
    if(i != h - 1 && (a[i][w - 1] & 1)){
      a[i][w - 1]--;
      a[i + 1][w - 1]++;
      ans.push_back({i, w - 1, i + 1, w - 1});
    }
  }
  cout << ans.size() << endl;
  if(!ans.size()) return 0;
  for(vi res : ans) cout << res[0] + 1 << " " << res[1] + 1 << " " << res[2] + 1 << " " << res[3] + 1 << endl;
}