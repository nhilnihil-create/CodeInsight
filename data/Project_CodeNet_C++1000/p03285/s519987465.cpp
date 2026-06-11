#include <iostream>
using namespace std;

int main(){
  int N;
  cin >> N;
  bool ans = false;
  for(; N >= 4; N -= 4){
    if((N % 4)*(N % 7) == 0){
      ans = true;
    }
  }
  if(ans){
    cout << "Yes";
  }else{
    cout << "No";
  }
  return 0;
}
