#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using ld = long double;
long double const pi = std::acos(-1.0L);
typedef pair<int,int> P;
const int INF = 1001001001;
ll n;
int dfs(string &S){
  ll ret = 0;
  vector<char> lis = {'3', '5', '7'};
  if((int)S.size()>0){
    if(stoll(S) > n){
      return ret;
    }else {
      bool ok = true;
      for(auto c : lis){
        if(S.find(c) == string::npos) ok = false;
      }
      if (ok) ret++;
    } 
  }
  for(auto c : lis){
    S.push_back(c);
    ret += dfs(S);
    S.pop_back();
  }
  return ret;
}

int main() {
  cin >> n;
  string S = "";
  cout << dfs(S) << endl;
  return 0;
}