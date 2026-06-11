#include <bits/stdc++.h>
using namespace std;
#define Q 1000000
int main() {
  int s;
  cin >> s;
  bool check=false;
  vector<int> A(Q);
  A.at(0) = s;
  for(int i=0;i<Q;i++){
    if(A.at(i)%2==0){
      A.at(i+1)=A.at(i)/2;
    }else{
      A.at(i+1)=3*A.at(i)+1;
    }
    for(int j=0;j<i;j++){
      if(A.at(j)==A.at(i)){
        s=i;
        check = true;
      }
    }
    if(check){
      break;
    }
  }
  cout << s+1 << endl;
}

