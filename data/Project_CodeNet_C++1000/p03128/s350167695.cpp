#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll longinf=1LL<<60;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second

const int mx=100010;
const ll mod=1e9+7;

vector<int> a;
vector<int> num={1000,2,5,5,4,5,6,3,7,6};
vector<string> dp(10010);

bool large(string& s, string& t){
  if(s.size()!=t.size()){ return s.size()>t.size(); }
  return s>t;
}

string rec(int n){
  if(dp[n]!=""){ return dp[n]; }
  if(n==0){ return ""; }
  string ret="";
  for(auto to:a){
    if(n-num[to]>=0){
      string now = (char)(to+'0')+rec(n-num[to]);
      if(now.back()=='x'){ continue; }
      if(large(now,ret)){ ret = now; }
    }
  }
  if(ret==""){ ret = "x"; }
  return dp[n] = ret;
}

int main(){
  int n,m;
  cin >> n >> m;

  rep(i,m){ int k; cin >> k; a.emplace_back(k); }  
  string ans=rec(n);
  cout << ans << endl; 
  return 0;
}
