#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  vector<int> p(n);
  for (int& x: p) cin>>x;
  sort(p.begin(), p.end());
  int res = std::accumulate(p.begin(),p.end(),0) - p.back()/2;
  cout<<res<<endl;
  return 0;
  
}