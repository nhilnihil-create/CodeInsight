#include <bits/stdc++.h>
using namespace std;
//#include <atcoder/all>
//using namespace atcoder;
template <typename T> bool chmax(T &u, const T z) { if (u < z) {u = z; return true;} else return false; }
template <typename T> bool chmin(T &u, const T z) { if (u > z) {u = z; return true;} else return false; }
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
typedef pair<ll, ll> P;
const ll INF = 1LL << 60;
//const int MOD = 1000000007;
ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }

int main(){
  string s;
  cin>>s;
  int cnt=0;
  while(!s.empty()){
    if(s[0]==s[s.size()-1]){
      s.erase(s.size()-1,1);
      s.erase(0,1);
    }else if(s[0]!='x'&&s[s.size()-1]=='x'){
      cnt++;
      s.erase(s.size()-1,1);
    }else if(s[0]=='x'&&s[s.size()-1]!='x'){
      cnt++;
      s.erase(0,1);
    }else{
      cout<<-1<<endl;
      return 0;
    }
  }
  cout<<cnt<<endl;
  return 0;
  }