#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007



int main(){

  int n;
  cin >> n;
  vector<int> v(n+1);
  rep(i,n)cin >> v[i+1];
  vector<int> res;
  rep(times,n){
    for(int i = v.size()-1;i > 0;i--){
      if(i == v[i]){
        v.erase(v.begin()+i);
        res.push_back(i);
        break;
      }
    }
  }
  if(res.size() == n)for(int i = n-1;i >= 0;i--)cout << res[i] << endl;
  else cout << -1 << endl;
  


  return 0;
}
