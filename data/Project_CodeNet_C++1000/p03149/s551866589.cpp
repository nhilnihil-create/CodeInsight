#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> A(4);
  for(int i=0;i<4;i++){
    cin >>A.at(i);
  }
  sort(A.begin(),A.end());
  if(A.at(0)!=1){
    cout <<"NO" <<endl;
    return 0;
  }
  if(A.at(1)!=4){
    cout <<"NO" <<endl;
    return 0;
  }
  if(A.at(2)!=7){
    cout <<"NO" <<endl;
    return 0;
  }
  if(A.at(3)!=9){
    cout <<"NO" <<endl;
    return 0;
  }
  cout <<"YES" <<endl;
  return 0;
}