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
#define ll  long long 
#define rep(i, n)        for(ll i=0; i<(ll)(n); ++i)
#define mod 1000000007
  //vector<ll>to[1000005];
  // ll dp[2000000];
 int gcd(int a, int b)
{
  if (a%b == 0)
{
return(b);
}
else
{
return(gcd(b,a%b));
}
}
int main(){
  ll a,b,ans=0;cin>>a>>b;
  vector<vector<ll>>c(a);
  rep(i,b){
    ll e,d;cin>>e;
    rep(o,e){
      cin>>d;
      c[d-1].push_back(i);
    }
  }
  vector<ll>d(b);
  rep(i,b)cin>>d[i];
  rep(i,1<<a){
    vector<ll>e(b,0);
    rep(o,a)if(i>>o&1)rep(j,c[o].size())e[c[o][j]]++;
    rep(o,b){
      if(e[o]%2!=d[o])break;
      if(o==b-1)ans++;
  }
  }
  cout<<ans;
}

