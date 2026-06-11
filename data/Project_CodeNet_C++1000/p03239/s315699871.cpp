#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,t;
  cin >> n >> t;
  vector<int> cost(0);
  for(int i=0;i<n;i++){
    int x,y;  cin >> x >> y;
    if(y<=t) cost.push_back(x);
  }
  sort(cost.begin(),cost.end());
  if(cost.size()>0) cout << cost.at(0) << endl;
  else cout << "TLE" << endl;
}