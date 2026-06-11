#include <bits/stdc++.h>
using namespace std;
using pp = pair<int, int>;
const vector<int> dx = {0, 0, -1, 1};
const vector<int> dy = {1, -1, 0, 0};

int main(){
  int n;
  cin >> n;
  vector<int> x(n);
  for(int i = 0; i < n; i++) cin >> x.at(i);
  
  auto c = x;
  sort(x.begin(), x.end());
  
  for(int i = 0; i < n; i++){
    if(c.at(i) < x.at(n/2)) cout << x.at(n/2) << endl;
    else cout << x.at(n/2 - 1) << endl;
  }
}