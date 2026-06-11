#include <iostream>
using namespace std;

int main(){
  int N;
  cin >> N;
  int n = N;
  int sum = 0;
  while(n>0){
    sum += n%10;
    n /= 10;
  }
  if(N%sum == 0){
    cout << "Yes";
  }else{
    cout << "No";
  }
  return 0;
}