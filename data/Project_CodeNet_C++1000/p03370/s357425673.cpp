#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, x;
  cin >> n >> x ;
  vector <int> c(n);
  int sum =0 ;
  int ans =0 ;
  for (int i=0 ; i<n ;i++){
    cin >> c.at(i);
    sum += c.at(i);
  }
  sort ( c.begin(), c.end()) ;
  ans = n+(x-sum)/c.at(0) ;
  cout << ans << endl;
}