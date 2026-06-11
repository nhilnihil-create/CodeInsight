#include <bits/stdc++.h>
using namespace std;

int main(){
  string A;
  cin >> A;
  int ans=700;
  for(int i=0;i<3;i++){
    if(A.at(i)=='o'){
      ans+=100;
    }
  }
  cout << ans << endl;
}
