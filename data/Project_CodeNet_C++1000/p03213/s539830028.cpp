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
int cnt(int n, vi &sosu){
  int ans = 0;
  for(int i : sosu){
    if(i >= n - 1) ans++;
  }
  return ans;
}
int main(){
  int n;
  cin >> n;
  vi sosu(n + 1, 0);
  for(int i = 2; i <= n; i++){
    int num = i;
    for(int j = 2; j <= n; j++){
      while(num % j == 0){
        num /= j;
        sosu[j]++;
      }
    }
  }
  int v5 = cnt(5, sosu), v3 = cnt(3, sosu) - 1;
  int ans = cnt(75, sosu);
  ans += cnt(25, sosu) * v3;
  ans += cnt(15, sosu) * (v5 - 1); 
  ans += v5 * (v5 - 1) / 2 * (v3 - 1);
  cout << ans << endl;
}