#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  vector <int> A(4);
  int num = 0;
  vector<char> hugou(3);
  cin >> N;
  for(int i = 0; i < 4; i++){
    A.at(i) = N % 10;
    N /=10;
  }
  reverse(A.begin(),A.end());
  for(int i = 0; i < (1 << 3); i++){
  	bitset<3> ope(i);
    
    if(ope.test(0)){
      num = A.at(0) + A.at(1);
      hugou.at(0) = '+';
    }
    else{
      num = A.at(0) - A.at(1);
      hugou.at(0) = '-';
    }
    if(ope.test(1)){
      num += A.at(2);
      hugou.at(1) = '+';
    }
    else{
      num -= A.at(2);
      hugou.at(1) = '-';
    }
    if(ope.test(2)){
      num += A.at(3);
      hugou.at(2) = '+';
    }
    else{
      num -= A.at(3);
      hugou.at(2) = '-';
    }
    if(num == 7){
      cout << A.at(0) << hugou.at(0) 
           << A.at(1) << hugou.at(1)
           << A.at(2) << hugou.at(2)
           << A.at(3) << "=7" << endl;
      break;
    }
    num = 0;
  }
}