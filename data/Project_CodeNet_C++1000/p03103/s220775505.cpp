#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  vector<pair<int,int>> p(n);
  for (int i=0;i<n;++i) cin >> p[i].first >> p[i].second;
  sort(p.begin(),p.end());
  
  long long ans=0;
  for (int i=0;i<n;++i){
    long long buy = min(m,p[i].second);
    ans += buy*p[i].first;
    m-=buy;
  }
  cout << ans << endl;
}
