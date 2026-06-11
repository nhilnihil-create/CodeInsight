/*
* Welcome to my code!
*---------------------------------------------*
* author : lynmisakura(twitter : @andoreiji11)
*/

#include <iostream>
#include <limits.h>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <cassert>

using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define repn for(int i = 0;i < n;i++)
#define ain(a) for(auto& i : a)cin >> i;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x.size())
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define cont continue

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using pi = pair<int,int>;
using vpi = vector<pi>;
using pl = pair<ll,ll>;
using vpl = vector<pl>;

template<class T> bool chmin(T& a,T b){if(a > b){a = b;return true;}else return false;}
template<class T> bool chmax(T& a,T b){if(a < b){a = b;return true;}else return false;}
template<class T> void print(std::vector<T> a){ int sz = a.size();
for(int i=0;i<a.size();i++)cout << a[i] << (i < sz-1 ? ' ' : '\n'); }
void ioboost(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}
///////////////////////////////////////////////////////////

// [lb,ub)の範囲の個数を数える
template<class T> int get_range_cnt(vector<T>& a,T lb,T ub){
  int n = a.size();

  int r = n - (int)(a.end() - (lower_bound(all(a),ub)));
  int l = n - (int)(a.end() - (lower_bound(all(a),lb)));

  return r - l;
}

int main(void){
  ioboost();

  int n;cin >> n;
  vl a(n),b(n);
  rep(i,n)cin >> a[i];
  rep(i,n)cin >> b[i];

  ll ans = 0;

  for(int k = 0;k <= 29;k++){
    vl na(n),nb(n);
    rep(i,n)na[i] = a[i] % (1LL << (k+1));
    rep(i,n)nb[i] = b[i] % (1LL << (k+1));

    sort(all(na));
    sort(all(nb));

    ll res = 0; // how many pairs satifsied?

    rep(i,n){
      res += get_range_cnt(nb,(1LL<<k) - na[i],(1<<(k+1)) - na[i]);
      res += get_range_cnt(nb,(1LL<<(k+1))+(1LL<<k) - na[i],(1LL<<(k+2)) - na[i]);
    }

    res %= 2;
    ans += (1LL << k) * res;

  }

  cout << ans << '\n';
}