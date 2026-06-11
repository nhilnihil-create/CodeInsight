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
  int n,m,Q;
  cin >> n >> m >> Q;
  vvi v(n, vi(n, 0));
  rep(i, m){
    int l,r;
    cin >> l >> r;
    l--; r--;
    v[l][r]++;
  }
  vvi rui(n + 1, vi(n + 1, 0));
  rep(i, n) rep(j, n) rui[i + 1][j + 1] = rui[i + 1][j] + rui[i][j + 1] - rui[i][j] + v[i][j];
  rep(i, Q){
    int p,q;
    cin >> p >> q;
    p--;
    int ans = rui[q][q] - rui[q][p] - rui[p][q] + rui[p][p];
    cout << ans << endl;
  }
}