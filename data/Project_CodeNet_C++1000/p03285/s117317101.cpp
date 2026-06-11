#include <bits/stdc++.h>
using namespace std;
main(){
  int N;
  cin >> N;
  int sum=0;
  string ans="No";
  for(int i=0;i<30;i++){
    for(int j=0;j<30;j++){
      sum=4*i+7*j;
      if(sum==N) ans="Yes";
    }
  }
  cout << ans << endl;
}