#include <iostream>
using namespace std;

int main(){
  int s, cnt = 0;
  cin >> s;
  if(s/100 == 1){
    cnt++;
    s -= 100;
  }
  if(s/10 == 1){
    cnt++;
    s -= 10;
  }
  if(s == 1){
    cnt++;
  }

  cout << cnt << endl;


  return 0;
}