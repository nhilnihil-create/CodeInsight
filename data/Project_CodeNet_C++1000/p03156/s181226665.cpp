#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < n; ++i)
using namespace std;

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  vector<int> f,s,t;
  rep(i, n){
    int c;
    cin >> c;
    if(c <= a) f.push_back(c);
    else if(c <= b) s.push_back(c);
    else t.push_back(c);
  }
  cout << min(f.size(), min(s.size(), t.size())) << endl;
  return 0;
}