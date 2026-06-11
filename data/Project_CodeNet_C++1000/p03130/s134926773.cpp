#include <bits/stdc++.h>
using namespace std;
int main () {
  vector<int> data(4);
  int a;
  for(int i = 0; i < 6; i++){
    cin >> a;
    data.at(a - 1)++;
  }
  int one = 0, two = 0;
  for(int i = 0; i < 4; i++){
    if(data.at(i) == 2)two++;
    if(data.at(i) == 1)one++;
  }
  int flag = 0;
  if(one == 2 && two == 2)flag = 1;
  cout << (flag ? "YES": "NO") << endl;
  return 0;
}
