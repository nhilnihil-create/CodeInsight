#include<bits/stdc++.h>
using namespace std;

int main(){
  
  vector<int> cst(3);
  cin >> cst[0] >> cst[1] >> cst[2];
  sort(cst.begin(), cst.end());
  
  cout << cst[2] - cst[0] << endl; 
  return 0;
}