#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int num1 = 0;
  int num2 = 0;
  cin >> num1 >> num2;
  double result = (num1 + num2) / 2.0;
  int compare = (num1 + num2) / 2;
  
  if (result + 0.9 >= compare + 1){
    result = compare + 1;
  }
  cout << result << endl;
}