#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int num1,num2;
  cin >> num1 >> num2;
  
  int num,count = 0;
  
  for (int i = 0; i <= num2 - num1; i++){
    num = num1 + i;
    if(num % 10 == num / 10000  && num / 10 % 10 == num / 1000 % 10)
      count++;
  }
    cout << count << endl;
 
}