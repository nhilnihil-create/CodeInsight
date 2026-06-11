#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<int> c(9);
  for(int i=0;i<9;i++) cin >> c.at(i);
  
  int ans=1;
  
  ans*=(c[3]-c[0]==c[4]-c[1]&&c[3]-c[0]==c[5]-c[2]);
  ans*=(c[3]-c[6]==c[4]-c[7]&&c[3]-c[6]==c[5]-c[8]);
  ans*=(c[0]-c[1]==c[3]-c[4]&&c[0]-c[1]==c[6]-c[7]);
  ans*=(c[2]-c[1]==c[5]-c[4]&&c[2]-c[1]==c[8]-c[7]);
  
  if(ans) cout << "Yes" << endl;
  else cout << "No" << endl;
}