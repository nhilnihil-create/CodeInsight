#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
#define rep(i,w) for (int i = 0;i < (w); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int INF = 1e9;

int main(){
  int x,y,z,k;cin >> x >> y >> z >> k;
  vector<ll> a(x),b(y),c(z);
  rep(i,x) cin >> a[i];
  rep(i,y) cin >> b[i];
  rep(i,z) cin >> c[i];
  vector<ll> bc(1000005);
  rep(i,y)rep(j,z) bc[i*z+j] = b[i]+c[j];
  sort(bc.rbegin(),bc.rend());
  multiset<ll,greater<ll>> ans;
  rep(i,x)rep(j,k) ans.insert(a[i]+bc[j]);
  multiset<ll>::iterator it = ans.begin();
  rep(i,k) {
    cout << *it << endl;
    it++;
  } 
  
  
}