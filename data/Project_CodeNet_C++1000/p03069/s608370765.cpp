#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
const int INT_INF = 2147483647;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main(){
  int n;
  cin >> n;
  char s[n];
  rep(i,n)cin >> s[i];
  vector<int>v;
  rep(i,n){
    if(s[i]=='#')v.push_back(i);
  }
  vector<int> ans;
  rep(i,v.size()){
    int t=0;
    t+=i;
    t+=n-v[i]-1-(v.size()-(i+1));
    ans.push_back(t);
  }
  ans.push_back(v.size());
  ans.push_back(n-v.size());
  int res = 1000000;
  rep(i,ans.size()){
    //cout << ans[i] << endl;
    chmin(res,ans[i]);
  }
  cout << res << endl;
}
