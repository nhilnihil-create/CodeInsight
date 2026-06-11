#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<vector<char>> c(2, vector<char>(3));
  for (int i=0 ; i<2 ; i++){
    for (int j=0 ; j<3 ; j++)
      cin >> c.at(i).at(j);
  }
  
  int n = 0;
  for (int i=0 ; i<3 ; i++){
    if (c.at(0).at(i) == c.at(1).at(2-i))
      n++;
  }
  
  if (n == 3)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}