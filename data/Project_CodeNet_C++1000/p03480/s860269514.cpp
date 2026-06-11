#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <time.h>
#include <list>

using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define reps(x,c) for(auto x:c)
#define all(x) begin(x), end(x)
#define pb(a) emplace_back(a) 
#define mp(a,b) make_pair((a),(b))
#define pl pair<ll,ll>
#define INF 2147483600
#define MOD 1000000007
#define fi first
#define se second
#define dbg(x) cout << #x"="<< (x) << endl
#define dbgv(x) cout<<#x<<endl;reps(y,x){cout<<y<<" ";}cout<<endl

int main(){
  string s;cin>>s;
  ll limit=s.size();
  rep(i,s.size()){
    if(s[i]!=s[i+1]){
      limit=min(limit,max(ll(i+1),ll(s.size()-i-1)));
    }
  }
  cout<<limit<<endl;
}