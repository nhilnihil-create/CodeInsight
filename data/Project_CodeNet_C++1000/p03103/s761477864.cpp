#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<string,int>;
const double PI = acos(-1);
int main() {
int n,m;
cin >> n >> m;
vector<vector<int>> x(n,vector<int>(2));
rep(i,n)rep(j,2)cin >> x.at(i).at(j);

sort(x.begin(),x.end());
ll cnt = 0;
ll ans = 0;
rep(i,n){
  for(ll j = 1; j <= x.at(i).at(1); j++){
    
    ans += x.at(i).at(0);
    cnt++;
    if(cnt == m){
      cout << ans << endl;
      return 0;
    }
  }
}
} 