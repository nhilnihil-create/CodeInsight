#include <vector>
#include <math.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <deque>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;
#define rep(i, n) for(int i = 0; i<n; i++)
#define rep_s(i, start, n) for(int i= start;  i<n; i++)
#define ALL(a) (a).begin(), (a).end()
string alphabet_upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string alphabet_lower  = "abcdefghijklmnopqrstuvwxyz";

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


int main(void){
  int N, K;
  cin >> N >> K;
  ull ans = 0;
  rep_s(i, 1, N+1){
    int div_num = N/i;
    int amari = N%i; 
    //cout << "i: " << i << ", div_num*max(0, i-K): " << div_num*max(0, i-K) << ", max(0, amari-K+1)" << max(0, amari-K+1)<<endl;
    ans += div_num*max(0, i-K);
    ans += max(0, amari-K+1);
    if (K==0) ans--;
  }
  cout << ans << endl;
}
