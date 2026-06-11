#include<bits/stdc++.h>
using namespace std;
  
int main(){
  string S;
  cin >> S;
  int K,A=S.size();
  cin >> K;
  for(int i=0;i<min(A,K);i++){
    if(S.at(i)!='1'){
      cout << S.at(i) << endl;
      return 0;
    }
  }
  cout << 1 << endl;
}