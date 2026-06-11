#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(x) x.begin(), x.end()
#define mod 1000000007
#define inf 1000000000
typedef long long ll;

int main(){
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> vec;
  rep(i, m){
    int a, b;
    cin >> a >> b;
    vec.push_back(make_pair(a, b));
  }
  int cnt = 0;
  rep(k, m){
    vector<int> dest(n, inf);
  	dest[0] = 0;
    rep(i, n){
      rep(j, m){
        if(j == k) continue;
        if(dest[vec[j].first] + 1 < dest[vec[j].second]) dest[vec[j].second] = dest[vec[j].first] + 1;
        if(dest[vec[j].second] + 1 < dest[vec[j].first]) dest[vec[j].first] = dest[vec[j].second] + 1;
      }
    }
    bool reachable = true;
  	rep(i, n){
   	  if(dest[i] == inf) reachable = false;
  	}
    if(!reachable) cnt++;
  }
  cout << cnt << endl;
  return 0;
}
        
      
      
      
      
      
      
      
  