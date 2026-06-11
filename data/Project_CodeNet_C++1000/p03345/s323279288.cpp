#include <iostream>

using namespace std;

int main(){
int A, B, C;
  long long K;
  cin >> A >> B >> C >> K;
  
  //Kが奇数
  if(K&1 == 1)
    cout << B-A << endl;
  //Kが偶数のとき
  else
  	cout << A-B << endl;
  
return 0;
}