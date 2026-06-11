#include <bits/stdc++.h>
using namespace std;
#define rep(i,n); for(ll i = 0;i<n;++i)
using ll = long long;
using P = pair<string,int>;

int main(){
  int n,a,b;
  cin >> n >> a >> b;
  vector<int> p(n);
  rep(i,n) cin >> p[i];
  sort(p.begin(),p.end());
  int x = 0;
  int y = 0;
  int z = 0;
  rep(i,n){
    if(p[i] <= a) ++x;
    else if(p[i] <= b) ++y;
    else ++z;
  }
  cout << min(min(x,y),z) << endl;
  return 0;
}
