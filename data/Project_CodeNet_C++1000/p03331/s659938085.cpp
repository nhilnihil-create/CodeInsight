#include<bits/stdc++.h>
#include<math.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  int A, B, sum_digit, retval=1000;

  for (int i=1;i<N;i++){
    A = i;
    B = N - A;
    sum_digit = 0;
    while (A>0 || B>0){
      sum_digit += A%10 + B%10;
      A/=10;
      B/=10;
    }
    retval = min(retval, sum_digit);
  }
  cout << retval << endl;
}

  
  