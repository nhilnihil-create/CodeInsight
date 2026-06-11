#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
#define REP(i,s,n) for(int i = s; i < n; i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
using Graph = vector<vector<int>>;
const int INF = 1000000007;
int main(){
  int n;
  cin >> n;
  vector<int>b(n);
  rep(i,n)cin >> b[i];
  vector<int>ans;
  int sz = n;
  while(!b.empty()){
    int B = -1;
    rep(i,sz)if(b[i] == i + 1)B = i;
    if(B == -1){
      cout << -1 << endl;
      return 0;
    }
    ans.push_back(B + 1);
    b.erase(b.begin() + B);
    sz--;
  }
  reverse(all(ans));
  rep(i,n)cout << ans[i] << endl;

  return 0;
}
