#include <iostream>
using namespace std;

int main(){
  int A, B;
  cin >> A >> B;
  int ans = 0;
  for(int i=A; i<=B; i++){
    int x = i%100;
    int y = i/1000;
    if( ((x%10)==y/10) && ((y%10)==x/10) ){
      ans++;
    }
  }
  cout << ans;
  return 0;
}