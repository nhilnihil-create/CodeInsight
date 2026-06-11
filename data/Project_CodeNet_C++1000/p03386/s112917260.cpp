#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int a, b, k;
  cin >> a >> b >> k;
  vector<int> v(k);
  vector<int> w(k);
  for(int i=0; i<k; i++) v[i] = a+i;
  for(int i=0; i<k; i++) w[i] = b-k+1+i;
  
  set<int> s;
  for(int i=0; i<k; i++) {
    if(a<=v[i] && v[i]<=b) s.insert(v[i]);
    if(a<=w[i] && w[i]<=b) s.insert(w[i]);
  }
  for(auto t : s) cout << t << endl;
  return 0;
}