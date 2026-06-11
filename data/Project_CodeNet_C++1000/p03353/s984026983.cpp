#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define ALL(v) v.begin(),v.end()
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int>;
using vs = vector<string>;
using vb = vector<bool>;
using vll = vector<long long>;
using vpii = vector<pair<int,int>>;
using vivi = vector<vector<int>>;
using vbvb = vector<vector<bool>>;
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
const int mod = 1000000007;
const int inf = 1001001001;

int main(void) {
  string s;int k;
  cin >> s >> k;
  set<string> ans;
  int n = s.size();
  rep(i,n){
    rep(j,5){
      if(i+j+1>n)continue;
      ans.insert(s.substr(i,j+1));
    }
  }
  while(true){
    if(k==1){
      cout << *begin(ans) << endl;
      return 0;
    }
    ans.erase(*begin(ans));
    k--;
  }
    
}


