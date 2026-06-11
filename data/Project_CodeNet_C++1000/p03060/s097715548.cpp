#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

const long long MOD = 1000000007;

int main(){
  int n;
  cin >> n;
  vector<int> v(n),c(n);
  rep(i,n) cin >> v.at(i);
  rep(i,n) cin >> c.at(i);
  int ans=0;
  rep(i,n){
      if(v.at(i)-c.at(i)>0) ans+=v.at(i)-c.at(i);
  }
  cout << ans << endl;
}
