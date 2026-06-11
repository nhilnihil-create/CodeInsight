#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<string,int>;
const double PI = acos(-1);
int main() {
int n,k;
cin >> n >> k;
map<int,int> mp;
rep(i,n){
  int x;
  cin >> x;
  mp[x]++;
}
if(mp.size() <= k) cout << 0 << endl;
else{
  int a = mp.size()-k;
  vector<int> b;
  for(auto itr = mp.begin(); itr != mp.end(); itr++){
    b.push_back(itr->second);
  }
  sort(b.begin(),b.end());
  int ans = 0;
  rep(i,a) ans += b.at(i);
  cout << ans << endl;
}


} 