#include<iostream>
using namespace std;

int main(){
  string S;
  cin >> S;
  int sum = 0;
  for(int i=0; S[i]!='\0'; i++){
    if(S[i] == 'o'){
      sum += 100;
    }
  }
  cout << 700 + sum << endl;
  return 0;
}
