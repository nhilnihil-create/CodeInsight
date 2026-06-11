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
  vi v(n);
  rep(i, n) cin >> v[i];
  //vi a(100001), b(100001);
  vector<pair<int, int>> a(100001, make_pair(0, 0)), b(100001, make_pair(0, 0));
  rep(i, 100001){
    a[i].second = i;
    b[i].second = i;
  }
  for(int i = 0; i < n; i += 2) a[v[i]].first++;
  for(int i = 1; i < n; i += 2) b[v[i]].first++;
  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());
  sort(b.begin(), b.end());
  reverse(b.begin(), b.end());
  if(a[0].second == b[0].second){
    if(a[1].first > b[1].first){
      cout << n - a[1].first - b[0].first << endl;
    }else{
      cout << n - a[0].first - b[1].first << endl;
    }
  }else{
    cout << n - a[0].first - b[0].first << endl;
  }
}