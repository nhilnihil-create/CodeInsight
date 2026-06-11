#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

int main() {
 int n;
  cin >> n;
  
  vector<int> a(n);
  rep(i,n) {
  cin >> a.at(i);
  }
  
  sort(a.begin(), a.end());
  int sum = 0;
  rep(i,n-1){
  sum += a.at(i);
  }
  
  if(sum > a.at(n - 1)) {
    cout << "Yes";
  }
  else {
 cout << "No";
  }
  
}