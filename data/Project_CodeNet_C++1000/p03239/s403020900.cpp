#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,t;
  cin >> n >> t;
  vector<pair<int,int>> a(n);
  vector<int> b;
  for(int i = 0; i < n; ++i){
    cin >> a[i].first >> a[i].second;
    if(a[i].second <= t){
      b.push_back(a[i].first);
    }
  }
  b.push_back(0);
  if(b[0] == 0){
    cout << "TLE" << endl;
  }else{
    sort(b.begin(),b.end());
    cout << b[1] << endl;
  }
}