#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<long long> a(n), b(n);
  for(int i = 0; i < n; ++i) cin >> a[i];
  for(int i = 0; i < n; ++i) cin >> b[i];
  long long cnt = 0;
  for(int i = 0; i < n; ++i){
    if(a[i] <= b[i]) cnt += (b[i] - a[i]) / 2;
    else cnt -= (a[i] - b[i]);
  }
  cout << (cnt >= 0 ? "Yes" : "No" ) << endl; 
}