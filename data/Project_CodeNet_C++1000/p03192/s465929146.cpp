#include<iostream>
using namespace std;
int main(){
  int ans = 0;
  for(int i = 0; i < 4;++i){
    ans += cin.peek() == '2';
    cin.ignore();
  }
  cout << ans << endl;
}