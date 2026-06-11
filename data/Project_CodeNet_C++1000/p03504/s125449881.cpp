#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
#define rep(i,w) for (int i = 0;i < (w); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int INF = 1e9;

template<typename T>
struct BIT{
  int n;
  vector<T> d;
  BIT(int n = 0):n(n),d(n+1){}
  void add(int i,T x=1){
    for(i++;i<=n;i += i&-i){
      d[i] += x;
    }
  }
  T sum(int i){
    T x = 0;
    for(i++;i>0;i -= i&-i){
      x += d[i];
    }
    return x;
  }
};
 
int main(){
  int n,c;cin >> n >> c;
  vector<vector<int>> prog(30,vector<int>(100005));
  rep(i,n){
    int s,t,ci;cin >> s >> t >> ci;
    --ci;
    --s;
    --t;
    prog[ci][s]++;
    prog[ci][t]--;
  }
  rep(j,c)rep(i,100005) prog[j][i+1] += prog[j][i];
  //rep(i,20) cout << prog[2][i] << endl;
  int ans = 0;
  for(int i = 1;i < 100003;i++){
    int cnt = 0;
    int lcnt = 0;
    rep(j,c){
      if(prog[j][i]==1) cnt++;
      else if(prog[j][i-1]==1) lcnt++;
    }
    if(cnt > 0) cnt += lcnt;
    ans = max(ans,cnt);
  }
  cout << ans << endl;
}