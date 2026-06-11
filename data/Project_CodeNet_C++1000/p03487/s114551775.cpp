#include<bits/stdc++.h>
using namespace std;
int main(){
  int n; cin >> n;
  map<int, int> mp;
  for(int i = 0, temp; i < n; ++i){
    cin >> temp;
    mp[temp]++;
  }
  int ans = 0;
  for(auto a: mp){
    if(a.first > a.second) ans += a.second;
    else if(a.first < a.second) ans += (a.second - a.first);
  }
  cout << ans << endl;
}