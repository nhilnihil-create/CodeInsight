#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#include <iostream>
#include <set>
 
int main(void){
  int n;cin >> n;
  vector<int> d(n);for(int i=0;i<n;i++) cin >> d[i];
  set<int> s;
  for(int i=0;i<n;i++){
    s.insert(d[i]);
  }
  cout << s.size() <<endl;
  return 0;
}