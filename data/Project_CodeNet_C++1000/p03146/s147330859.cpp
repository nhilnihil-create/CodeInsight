#include <bits/stdc++.h>
using namespace std;

int main() {
  int S,ans=0;
  cin >> S;
  for (int i=0;;i++){
  if (S==4 || S == 2 || S==1){
  cout << ans+4 << endl;
  break;
  }
  else if (S%2==0){
  S/=2;
  ans++;
  }
  else if (S%2==1){
  S=S*3+1;
  ans++;
  }
  }
 }