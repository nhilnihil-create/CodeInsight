#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

int main() {
  int n;
  cin >> n;
  
  vector<int> a(n),b(n);
  rep(i,n) {
  cin >> a.at(i);
  }
  
  rep(i,n) {
  cin >> b.at(i);
  }
  
  int sum =0;
  
  rep(i,n) {
  if(a.at(i) > b.at(i)) {
   sum += (a.at(i) - b.at(i));
  }
     }
     
     cout << sum;
}