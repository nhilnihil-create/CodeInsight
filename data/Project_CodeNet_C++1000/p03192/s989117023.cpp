#include<iostream>

using namespace std;

int main(){
  int a;
  cin >> a;
  int answer = 0;
  while(a > 0){
    if(a%10==2)answer++;
    a/=10;
  }
  cout << answer << endl;
  
  return 0;
}