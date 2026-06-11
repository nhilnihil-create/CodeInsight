#include<bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;
  int L=S.size();
  int A=0, B=0;
  for(int i=0; i<L; i++){
    if(S.at(i)=='0'){
      A++;
    }
    else{
      B++;
    }
  }
  cout << A+B-abs(A-B) << endl;
}