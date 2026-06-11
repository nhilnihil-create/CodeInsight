#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define ll int64_t
#define _GLIBCXX_DEBUG
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main(){
  int n;
  cin >> n;
  int ans=-2000000000;
  vector<vector<int>> mise(n,vector<int>(10)),p(n,vector<int>(11));
  rep(i,n){
    rep(j,10)
      cin >> mise.at(i).at(j);
  }
  rep(i,n){
    rep(j,11)
      cin >> p.at(i).at(j);
  }
  for(int tmp=1;tmp<(1 << 10);tmp++){
    int pro=0;
    bitset<10> s(tmp);
    rep(i,n){
      int k=0;
      rep(j,10)
        if((mise.at(i).at(j)&&s.test(j)))k++;
      pro+=p.at(i).at(k);
    }
    ans=max(ans,pro);
  }
  cout << ans << endl;
}
        
    