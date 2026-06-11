#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<long long> a(n);
  for(int i = 0; i < n; i++){
    cin >> a.at(i);
    a.at(i) -= i - 1;
  }
  
  sort(a.begin(), a.end());
  int l = a.size();
  long long b;
  if(l == 1) b = a.at(0);
  else if(l%2) b = a.at(l/2);
  else b = a.at(l/2-1) + (a.at(l/2) - a.at(l/2-1))/2;
  
  long long ans = 0;
  for(int i = 0; i < l; i++){
    ans += abs(a.at(i) - b);
  }
  
  cout << ans << endl;
}