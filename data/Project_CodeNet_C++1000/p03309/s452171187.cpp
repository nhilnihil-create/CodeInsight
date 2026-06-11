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
  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n){
    ll A;
    cin >> A;
    A -= i + 1;
    a[i] = A;
  }
  sort(a.begin(), a.end());
  if(n % 2 == 0){
    ll ans = 0, ans2 = 0;
    ll num = a[n / 2];
    rep(i, n) ans += abs(a[i] - num);
    num = a[n / 2 - 1];
    rep(i, n) ans2 += abs(a[i] - num);
    ans = min(ans, ans2);
    cout << ans << endl;
  }else{
    ll num = a[n / 2];
    ll ans = 0;
    rep(i, n) ans += abs(a[i] - num);
    cout << ans << endl;
  }
}