#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,t;
  cin >> n >> t;
  vector<pair<int,int>> a(n);
  for(int i = 0; i < n; i++){
    cin >> a[i].first >> a[i].second;
  }
  sort(a.begin(),a.end());
  for(int i = 0; i < n; i++){
    if(a[i].second <= t){
      cout << a[i].first << endl;
      return 0;
    }
  }
  cout << "TLE" << endl;
  return 0;
}