#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
const int inf = 1001001001;

int main(){
  int n,m;
  cin >> n >> m;
  vector<int>x(m);


  if(n >= m){
    cout << 0 << endl;
    return 0;
  }
  
  rep(i,m) cin >> x[i];
  sort(x.begin(),x.end());

  vector<int> d(m-1);
  rep(i,m-1) d[i] = x[i+1]-x[i];
  sort(d.begin(),d.end());

  int ans = 0;
  rep(i,m-1-(n-1)){
    ans += d[i];
  }
  cout << ans << endl;
}
