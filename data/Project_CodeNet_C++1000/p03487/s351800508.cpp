#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n;
  map<int, int> mp;
  for(int i = 0; i < n; i++){
    int a; cin >> a;
    mp[a]++;
  }
  int ans = 0;
  for(auto p: mp){
    int k = p.first;
    int tmp = p.second;
    if(k < tmp) ans += tmp-k;
    else if(k > tmp) ans += tmp;
  }
  cout << ans << endl;
}