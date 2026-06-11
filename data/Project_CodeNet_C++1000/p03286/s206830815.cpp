#include<bits/stdc++.h>
using namespace std;

int main(){
  int64_t N;
  cin >> N;
  if(N==0){
    cout << 0 << endl;
  }
  vector<int64_t> A(51, 0);
  for(int64_t i=1; i<=50; i++){
    if(N%(int64_t)pow(2, i)!=0){
      A.at(i)=1;
      N-=(int64_t)pow(2, i-1)*(int64_t)pow(-1, i-1);
    }
  }
  int64_t P=0;
  for(int64_t i=50; i>0; i--){
    if(A.at(i)==1){
      P=1;
      cout << 1;
    }
    else if(P==1){
      cout << 0;
    }
  }
  cout << endl;
}
