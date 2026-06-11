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
#define mod 1000000007
using ll = long long;
using namespace std;
int main(){
  int n,m;
  cin >> n >> m;
  vector<ll> x(n), y(n), z(n);
  rep(i, n) cin >> x[i] >> y[i] >> z[i];
  ll ans = 0;
  for(int a = -1; a <= 1; a += 2) for(int b = -1; b <= 1; b += 2) for(int c = -1; c <= 1; c += 2){
    vector<ll> v(n);
    for(int i = 0; i < n; i++){
      v[i] = x[i] * a + y[i] * b + z[i] * c;
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    ll tot = 0;
    rep(k, m) tot += v[k];
    ans = tot > ans ? tot : ans;
  }
  cout << ans << endl;
}