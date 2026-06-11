#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int n = N;
  int sum = 0;
  while (n != 0){
  	int a = n % 10;
    n = (n - a) / 10;
    sum = sum + a;
  }
   if (N % sum == 0){
     cout << "Yes" << endl;
   }
  else {
    cout << "No" << endl;
  }
}
