#include <bits/stdc++.h>
using namespace std;

int main(){
  int a, b, c;
  cin >> a >> b >> c;
  
  vector<int> n = {a, b, c};
  sort(n.begin(), n.end());
  cout << n.at(2)*10 + n.at(1) + n.at(0) << endl;
}