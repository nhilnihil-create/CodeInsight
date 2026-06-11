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
  int n,k;
  string s;
  cin >> n >> k >> s;
  vi v;
  int cnt = 0, cnt2 = 0, count = 0;
  if(s[0] == '0') v.push_back(0);
  rep(i, n){
    if(s[i] == '1'){
      if(cnt2){
        v.push_back(cnt2);
        count++;
      }
      cnt++;
      cnt2 = 0;
    }else{
      if(cnt) v.push_back(cnt);
      cnt2++;
      cnt = 0;
    }
  }
  if(cnt) v.push_back(cnt);
  if(cnt2){
    v.push_back(cnt2);
    count++;
  }
  if(s[n - 1] == '0') v.push_back(0);
  if(count <= k) cout << n << endl;
  else{
    int ans = 0, num = 0;
    for(int i = 0; i < k * 2; i += 2){
      ans += v[i] + v[i + 1];
    }
    ans += v[k * 2];
    num = ans;
    for(int i = k * 2 + 1; i < v.size(); i += 2){
      num += v[i] + v[i + 1];
      num -= v[i - k * 2 - 1] + v[i - k * 2];
      ans = max(ans, num);
    }
    cout << ans << endl;
  }
}