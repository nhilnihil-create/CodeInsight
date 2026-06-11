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
  ll n;cin>>n;
  vector<ll> a(n);
    
  rep(i,n){
    cin>>a[i];
  }

  auto maxIt = max_element(all(a));
  size_t maxIndex = distance(a.begin(), maxIt);
  auto minIt = min_element(all(a));
  size_t minIndex = distance(a.begin(), minIt);
  if(abs(*maxIt)>abs(*minIt)){
    vector<string> ans;
    ans.pb(to_string(maxIndex+1)+" "+"1");
    a[0]+=*maxIt;   
    maxIt = max_element(all(a));
    maxIndex = distance(a.begin(), maxIt);
    ans.pb(to_string(maxIndex+1)+" "+"1"); 
    a[0]+=*maxIt;
    rep(i,n-1){
      ans.pb(to_string(i+1)+" "+to_string(i+2));  
      a[i+1]+=a[i];
      if(a[i+1]<a[i]){
        ans.pb(to_string(i+1)+" "+to_string(i+2));  
        a[i+1]+=a[i];
      }
    }

    cout<<ans.size()<<endl;
    rep(i,ans.size()){
      cout<<ans[i]<<endl;
    }
  }else{
    minIt = min_element(all(a));
    minIndex = distance(a.begin(), minIt);
    vector<string> ans;
    ans.pb(to_string(minIndex+1)+" "+to_string(n));
    a[n-1]+=*minIt;   
    minIt = min_element(all(a));
    minIndex = distance(a.begin(), minIt);
    ans.pb(to_string(minIndex+1)+" "+to_string(n));
    a[n-1]+=*minIt;
    rep(i,n-1){
      ans.pb(to_string(n-i)+" "+to_string(n-i-1));  
      a[n-i-2]+=a[n-i-1];
      if(a[n-i-1]<a[n-i-2]){
        ans.pb(to_string(n-i)+" "+to_string(n-i-1));  
        a[n-i-2]+=a[n-i-1];
      }
    }

    cout<<ans.size()<<endl;
    rep(i,ans.size()){
      cout<<ans[i]<<endl;
    }
  }

  return 0;
}