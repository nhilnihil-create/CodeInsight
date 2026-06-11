#include<iostream>
using namespace std;

int main(){
  int N;
  cin >> N;
  if(N==1){
    cout << 2 << endl;
  }else{
    cout << (N%2==0 ? N : 2*N) << endl;
  }
  
  return 0;
}
