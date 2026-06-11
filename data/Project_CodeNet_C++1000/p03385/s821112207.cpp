#include <iostream>
using namespace std;
int A[3] = {};
void conf(char a){
  if(a == 'a') A[0]++;
  else if(a == 'b') A[1]++;
  else A[2]++;
}

int main(){
  char c[3];
  for(int i = 0; i < 3; i++){
    cin >> c[i];
    conf(c[i]);
  }
  if(A[0] == 1 && A[1] == 1 && A[2] == 1){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}
  
