#include <bits/stdc++.h>
using namespace std;

int main(){
 
  int N;
  int A;
  cin >> N >> A;
  
  if (N % 500 == 0){
    cout << "Yes" << endl;
  }else if (N % 500 != 0 && A > N % 500){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  
  
}