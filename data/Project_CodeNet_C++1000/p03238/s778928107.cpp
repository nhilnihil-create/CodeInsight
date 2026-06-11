#include<iostream>
using namespace std;

int main(){
  int N;
  cin >> N;
  
  if(N==1){
    printf("Hello World\n");
  }
  
  if(N==2){
    int A, B;
    cin >> A >> B;
    printf("%d\n", A+B);
  }
  return 0;
}
