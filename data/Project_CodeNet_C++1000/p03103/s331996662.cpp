#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  
  vector<pair<int,int>> a;
  for(int i = 0; i < n; ++i){
    int p,q;
    cin >> p >> q;
    a.push_back({p,q});
  }
  sort(a.begin(),a.end());
  
  long long int res = 0;
  int c = 0;
  
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < a[i].second; ++j){
      ++c;
      res += a[i].first;
      if (c == m){
        break;
      }
    }
    if(c == m){
      break;
    }
  }
  
  cout << res << endl;
    
}