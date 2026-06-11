#include <iostream>
using namespace std;

int main(){
  int N;
  cin >> N;
  int ans = 0;
  while(N > 0){
    ans += (N%10 == 2);
    N /= 10;
  }
  cout <<  ans << endl;
}
