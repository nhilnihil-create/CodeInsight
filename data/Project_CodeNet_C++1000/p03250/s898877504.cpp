#include <bits/stdc++.h>
using namespace std;
int main() {
  int a,b,c;
  cin >> a >> b >> c;
  
  vector<int> vec = {10*a+b+c, 10*b+a+c,10*c+a+b};
  sort(vec.begin(),vec.end());
  cout << vec.at(2) << endl;
}
