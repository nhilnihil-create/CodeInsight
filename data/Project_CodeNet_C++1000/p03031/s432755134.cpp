#include <bits/stdc++.h>
#define rep(i, n) for(int i= 0; i < (n); i++)
using ll= long long int;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
ll mod= 1e9 + 7;


int main(){
  int n,m;
  cin >> n >> m;
  int k[m];
  vector<vector<int>> ss(m);
  int p[m];

  rep(i,m){
    cin >> k[i];
    rep(ii,k[i]){
      int d;
      cin >> d;
      ss[i].push_back(d);
    }
  }

  rep(i,m)cin >> p[i];
  int ans=0;



  for (int tmp = 0; tmp < (1 << n); tmp++) {
    bitset<12> s(tmp);//これで0101010といった数列を2^n個生成してくれる
    int pp=0;
    rep(i,m){
      int d=0;
      for(auto f:ss[i]){
        if(s[f-1])d++;
      }
      if((d+2)%2==p[i])pp++;
    }
    if(pp==m)ans++;
  }

  cout << ans << endl;
}