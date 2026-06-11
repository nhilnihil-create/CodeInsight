#include <bits/stdc++.h>
#define rep(i, e, n) for (int i = e; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const ll inf=1000000000007;

int main(){
  int n;
  cin >> n;
  vector<int> v(n);
  vector<int> c(n);
  rep(i,0,n) cin >> v[i];
  rep(i,0,n) cin >> c[i];
  int ans=0;
  rep(i,0,n){
    if(v[i]>c[i]){
      ans= ans + v[i] - c[i];
    }
  }
  cout << ans << endl;
}