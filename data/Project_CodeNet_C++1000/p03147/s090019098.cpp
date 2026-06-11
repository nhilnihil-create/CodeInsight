#include <bits/stdc++.h>
using namespace std;

int main(){
 int n; cin >> n;
 vector< int > v(n);
 //vector< int > zi(n);
 int h_min = INT_MAX;
 int h_max = INT_MIN;
 for(int i = 0; i < n; ++i){
   cin >> v[i];
   h_min = min(h_min,v[i]);
   h_max = max(h_max,v[i]);
 }
 //cout << h_min << ' ' << h_max << '\n';
 int ans = h_min;
 int count = h_min;
 bool flag = false;  
 for(int i = h_min; i <=  h_max; ++i){
  flag = false;
  for(int j = 0; j < n; ++j){
    if(v[j] - count > 0){
      if(!flag) ans++;
      flag = true;
    }
    else flag = false;
  }
   count++;
 }
 cout << ans << '\n';
}