#include <iostream>
#include <string>
#include <cmath>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  int min = 9999999;
  for(int i = 1; i < N;i++){
    int num1 = i;
    int num2 = N - i;
    int sum1 = 0;
    while(num1 > 0){
      sum1 += num1 % 10;
      num1 /= 10;
    }
    int sum2 = 0;
    while(num2 > 0){
      sum2 += num2 % 10;
      num2 /= 10;
    }
    if(min > sum1 + sum2) min = sum1 + sum2;
  }
  cout << min << endl;
}