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
void dfs(vector<vector<pii>> &root, vi &color, int current, vi &checked){
  for(pii a : root[current]){
    if(!a.second){
      color[a.first] = color[current];
    }else{
      color[a.first] = (color[current] ^ 1);
    }
    if(!checked[a.first]){
      checked[a.first] = 1;
      dfs(root, color, a.first, checked);
    }
  }
}
int main(){
  int n;
  cin >> n;
  vi color(n, -1);
  color[0] = 1;
  vector<vector<pii>> root(n);
  rep(i, n - 1){
    int u,v,w;
    cin >> u >> v >> w;
    u--; v--;
    w %= 2;
    root[u].push_back(make_pair(v, w));
    root[v].push_back(make_pair(u, w));
  }
  vi checked(n);
  dfs(root, color, 0, checked);
  rep(i, n) cout << color[i] << endl;
}