#include <iostream>
using namespace std;

int count(char *str){
  int i;
  int c = 0;
  for(i = 0; i < 3; i++){
    if(str[i] == '1'){
      c++;
    }
  }
  return c;
}

int main(){
  char strNum[3];
  cin >> strNum;
  cout << count(strNum);
}