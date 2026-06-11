#include<bits/stdc++.h>
using namespace std;

int main(){
  
  int N;
  int A;
  int B;
  
  cin >> N >> A >> B;
  
  int num = A + B - N;
  
  if(A <= B){
    cout << A << " ";
  }
  else{
    cout << B << " ";
  }
  
  if(num < 0){
    cout << 0 << endl;
  }
  else{
    cout << num << endl;
  }

}
