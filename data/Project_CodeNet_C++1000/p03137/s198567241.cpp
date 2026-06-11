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
  int n,m;
  cin >> n >> m;
  if(n >= m){
    cout << 0 << endl;
    return 0;
  }
  vi x(m);
  rep(i, m) cin >> x[i];
  sort(x.begin(), x.end());
  vi v(m - 1);
  rep(i, m - 1) v[i] = x[i + 1] - x[i];
  sort(v.begin(), v.end());
  int ans = x[m - 1] - x[0];
  rep(i, n - 1) ans -= v[m - 2 - i];
  cout << ans << endl;
}