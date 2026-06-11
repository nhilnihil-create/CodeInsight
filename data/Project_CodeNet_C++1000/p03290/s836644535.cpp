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
#include <chrono>
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

ll d,g;
ll p[11],b[11];

long long fscore(int id){
  return (id + 1) * p[id] + b[id];
}
long long func(ll mask){
  ll res = 0;
  ll now_p = 0;
  for (size_t i = 0; i < d; i++)
  {
    if(mask >> i & 1){
      now_p += fscore(i);
      res += p[i];
    }
  }

  if(now_p >= g){
    return res;
  }else{
    ll left = g - now_p;
    for (int i = d - 1; i >= 0; i--)
    {
      if(!(mask >> i & 1)){
        if((i+1)*(p[i] - 1) >= left){
          res += (left + i) / (i + 1);
          return res;
        }else{
          left -= fscore(i);
          res += p[i];
          if(left <= 0)return res;
        }
      }
    }
  }
  return res;
}

int main(void){
  cin >> d >> g;
  g /= 100;
  for (size_t i = 0; i < d; i++)
  {
    cin >> p[i] >> b[i];
    b[i] /= 100;
  }

  ll ans = 1LL << 55;
  for (size_t mask = 0; mask < 1 << d; mask++)
  {
    chmin(ans,func(mask));
  }
  cout << ans << '\n'; 
}