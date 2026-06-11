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
  vi a(n);
  rep(i, n) cin >> a[i];
  sort(a.begin(), a.end());
  vector<pii> v(m);
  rep(i, m){
    int b,c;
    cin >> b >> c;
    v[i] = make_pair(c, b);
  }
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  int cnt = 0, last = n;
  ll ans = 0;
  rep(i, n){
    if(v[cnt].second <= 0) cnt++;
    if(cnt < m && v[cnt].first > a[i]){
      v[cnt].second--;
      ans += v[cnt].first;
    }else{
      last = i;
      break;
    }
  }
  for(int i = last; i < n; i++) ans += a[i];
  cout << ans << endl;
}