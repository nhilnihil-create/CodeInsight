#include<iostream>
using namespace std;

int main(){
  string S;
  cin >> S;
  int result = 0;
  for(int i=0; S[i]!='\0'; i++){
    result += (S[i] == '+' ? 1 : -1);
  }
  cout << result << endl;
  return 0;
}