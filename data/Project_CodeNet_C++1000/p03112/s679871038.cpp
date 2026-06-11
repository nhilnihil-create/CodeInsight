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
ll findleft(vector<ll> &s, ll x){
  int left = -1, right = s.size();
  while(left + 1 < right){
    int middle = (right + left) / 2;
    if(s[middle] > x) right = middle;
    else left = middle;
  }
  if(left == -1 || left == s.size()) return 0;
  else return s[left] - x;
}
ll findright(vector<ll> &s, ll x){
  int left = -1, right = s.size();
  while(left + 1 < right){
    int middle = (right + left) / 2;
    if(s[middle] >= x) right = middle;
    else left = middle;
  }
  if(right == -1 || right == s.size()) return 0;
  else return s[right] - x;
}
int main(){
  int a,b,q;
  cin >> a >> b >> q;
  vector<ll> s(a), t(b);
  rep(i, a) cin >> s[i];
  rep(i, b) cin >> t[i];
  rep(i, q){
    ll x; cin >> x;
    ll ans = 10000000000000;
    ll spos1, spos2, tpos1, tpos2;
    spos1 = findleft(s, x);
    spos2 = findright(s, x);
    tpos1 = findleft(t, x);
    tpos2 = findright(t, x);
    if(spos2 && tpos1) ans = min(ans, 2 * (spos2 - tpos1) - max(spos2, -tpos1));
    if(tpos2 && spos1) ans = min(ans, 2 * (tpos2 - spos1) - max(tpos2, -spos1));
    if(spos1 && tpos1) ans = min(ans, -min(spos1, tpos1));
    if(spos2 && tpos2) ans = min(ans, max(spos2, tpos2));
    cout << ans << endl;
  }
}