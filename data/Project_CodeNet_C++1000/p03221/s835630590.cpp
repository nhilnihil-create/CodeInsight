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
#include <stdio.h>
string checkDigit(int n){
  int num = n;
  int cnt = 0;
  while(n){
    n /= 10;
    cnt++;
  }
  string s;
  string a = std::to_string(num);
  rep(i, 6 - cnt) s += "0";
  s += a.c_str();
  return s;
}
int main(){
  int n,m;
  cin >> n >> m;
  //vi p(m), y(m);
  vector<vector<pair<int,int>>> y(n);
  vector<string> v(m);
  rep(i, m){
    int p,x;
    cin >> p >> x;
    y[p - 1].push_back(make_pair(x, i));
  }
  rep(i, n) sort(y[i].begin(), y[i].end());
  rep(i, n){
    int cnt = 0;
    for(auto a : y[i]){
      cnt++;
      v[a.second] = checkDigit(i + 1) + checkDigit(cnt);
    }
  }
  rep(i, m) cout << v[i] << endl;
}