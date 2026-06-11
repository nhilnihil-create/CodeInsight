#include <bits/stdc++.h>
using namespace std;


int main(){
  
  int N;
  cin >> N;
  
  if(N % 3 == 0){
    cout << N / 3 << endl;
  }
  else if(N % 3 != 3 && N < 3){
    cout << "0" << endl;
  }
  else{
    cout << N / 3 << endl;
  }
  
}
