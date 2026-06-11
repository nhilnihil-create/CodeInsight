
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
#define rep(i, n)        for(int i=0; i<(int)(n); ++i)
#define ll  long long 
#define mod 1000000007
  vector<ll>to[1000005];
int main(){
  ll a,d;cin>>a;
  vector<vector<ll>>b(2,vector<ll>(a)),c(2,vector<ll>(a));
  rep(i,2)rep(o,a)cin>>b[i][o];
  c[0][0]=b[0][0];
  c[1][0]=c[0][0]+b[1][0];
  c[0][1]=c[0][0]+b[0][1];
    rep(o,a-1){
      c[0][o+1]=c[0][o]+b[0][o+1];
    }
    rep(o,a-1){
      c[1][o+1]=max(c[1][o]+b[1][o+1],c[0][o+1]+b[1][o+1]);
    }
    cout<<c[1][a-1];
}