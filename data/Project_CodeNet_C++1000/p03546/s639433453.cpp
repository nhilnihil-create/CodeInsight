#include<iostream>
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
#include <iomanip>//setprecision
#include<math.h>
#include <functional>
#include<climits>
using namespace std;
template <typename T> bool chmax(T &u, const T z) { if (u < z) {u = z; return true;} else return false; }
template <typename T> bool chmin(T &u, const T z) { if (u > z) {u = z; return true;} else return false; }
#define ll  long long 
const ll INF=1LL<<60;
#define rep(i, n)        for(ll i=0; i<(ll)(n); ++i)
ll cost[10][10];
ll n=1000;
int main(){
  ll a,b,c,ans=0;cin>>a>>b;
  rep(i,10)rep(o,10)cin>>cost[i][o];
  rep(i,10){
    n=min(cost[i][1],n);
  }
    rep(k,10)rep(i,10)rep(o,10)cost[i][o]=min(cost[i][o],cost[i][k]+cost[k][o]);
    rep(i,a*b){
      cin>>c;
      if(c==-1)continue;
      ans+=cost[c][1];
    }
    cout<<ans<<endl;
}
