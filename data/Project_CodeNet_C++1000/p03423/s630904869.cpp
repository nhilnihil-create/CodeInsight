#include <vector>
#include <math.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <deque>
#include <cctype>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<long, long>;
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;
#define rep(i, n) for(int i = 0; i<n; i++)
#define rep_s(i, start, n) for(int i= start;  i<n; i++)
#define ALL(a) (a).begin(), (a).end()
#define ALL_str(a) (a).cbegin(), (a).cend()

string alphabet_upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string alphabet_lower  = "abcdefghijklmnopqrstuvwxyz";
string numbers = "0123456789";

/*
using edge = struct {int to; ll cost;};
vector<edge> tree[limit];
ll depth[limit];

void dfs(int v, int p, ll d){
  depth[v] = d;
  //cout <<"v: " << v << endl;
  for (auto &e: tree[v]){
    //cout << "e.to: " << e.to << endl;
    if (e.to == p) continue;
    dfs(e.to, v, d+e.cost);
  }
}
*/
int keta_sum(int num){
  int dig, sum = 0;
  while(num){
    dig = num % 10;
    sum = sum + dig;
    num = num / 10;
  }
  return sum;
}

ll binary_search(ll left_key, ll border, ll low, ll high) {
     // 配列 a の左端と右端
    ll mid = (low+high)/2;
    while (high > low+1) {
       mid = (low+high)/2;
        if (left_key*mid>border) high = mid;
        else if (left_key*mid<border) low = mid;
        else {
          mid =mid-1;
          break;
        }
    }
    return mid;
}


int main(void){
  ll N, A, B, W, H, C, D, Q, X, Y;
  string S, T;
  cin >> N;
  cout << N/3 << endl;

}
