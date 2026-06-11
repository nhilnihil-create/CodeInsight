#include <iostream>
using namespace std;

int findSum(int n) {
    int sum = 0;
    while(n > 0){
        sum += n % 10;
        n /= 10;
    }
    return sum;
}


int main(){
  int a,b,N,X;
  X = 10000;
  cin >> N;
  for(a=1; a<N ;a++){
      b = N -a;
    if (X > findSum(a) + findSum(b)) {
        X = findSum(a) + findSum(b);
    }
  }
   cout << X << endl;
    
}