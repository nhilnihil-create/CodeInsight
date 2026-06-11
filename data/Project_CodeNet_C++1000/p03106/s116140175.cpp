#include <iostream>
using namespace std;

int main(){
  int A,B,K;
  cin >> A >> B >> K;
  int cnt =0;
  //今まで見つかった数
  for(int i=100;i>=1;i--){
    if ((A%i)==0 & (B%i)==0){
      cnt++;
    }
    if(cnt==K){ //K番目に大きい数が見つかった時のiが答えである
      cout << i <<endl;
      return 0;
    }
  }

}
