#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<int>A(5);
  for(int i=0;i<5;i++){
    cin >> A[i];
  }
  int k;
  cin >> k;
  bool C=true;
  sort(A.begin(),A.end());
  reverse(A.begin(),A.end());
  for(int i=0;i<5;i++){
    for(int j=4;j>i;j--){
      if(A[i]-A[j]>k){
        C=false;
        break;
      }
    }
    if(C==false){
      cout << ":(" << endl;
      break;
    }
  }
  if(C==true){
    cout << "Yay!" << endl;
  }
}
