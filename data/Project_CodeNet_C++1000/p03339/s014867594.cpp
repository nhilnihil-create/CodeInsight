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
  string s;
  cin >> n >> s;
  vi e(n + 1), w(n + 1);
  for(int i = 1; i <= n; i++){
    if(s[i - 1] == 'E') e[i] = 1;
    e[i] += e[i - 1];
    if(s[i - 1] == 'W') w[i] = 1;
    w[i] += w[i - 1];
  }
  int ans = n;
  for(int i = 1; i <= n; i++){
    if(s[i - 1] == 'E'){
      ans = min(ans, w[i] + e[n] - e[i]);
    }else{
      ans = min(ans, w[i - 1] + e[n] - e[i]);
    }
  }
  cout << ans << endl;
}