#include <bits/stdc++.h>
using namespace std;

int main(){
  
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++){
    cin >> a.at(i);
  }
  sort(a.begin(), a.end());
  int beg = a.at(0);
  reverse(a.begin(), a.end());
  int end = a.at(0);
  int ans = end - beg;
  
  cout << ans << endl;
  
}
