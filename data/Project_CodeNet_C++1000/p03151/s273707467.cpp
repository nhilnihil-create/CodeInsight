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
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  ll tot = 0, need = 0;
  vector<ll> plus;
  int cnt = 0;
  rep(i, n){
    int b; cin >> b;
    tot += a[i] - b;
    a[i] -= b;
    if(a[i] < 0){
      need -= a[i];
      cnt++;
    }else plus.push_back(a[i]);
  }
  if(tot < 0) cout << -1 << endl;
  else{
    sort(all(plus));
    ll total = 0;
    if(need){
      for(int i = plus.size() - 1; i >= 0; i--){
        total += plus[i];
        cnt++;
        if(total >= need) break;
      }
    }
    cout << cnt << endl;
  }
}