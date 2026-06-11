#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, y;
  cin >> x;
  y = x;
  
  // 桁数
  int n = 1;
  while(y >= 10){
  	y /= 10;
    n++;
  }
  
  vector<int> vec(n+1);
  int sum = 0;
  
  if (n > 1) {
     for (int i = 0; i < n; i++) {
       if(i == 0){
         vec.at(i) = x/10;
         sum += x % 10;
       } else {
         vec.at(i) = vec.at(i-1)/10;
         sum += vec.at(i-1) % 10;
       }
       
       //if(vec.at(i) < 10) sum += vec.at(i);
     }
  } else {
  	sum = x;
  }
  
  if (x % sum == 0){
  	cout << "Yes" << endl;
  } else {
  	cout << "No" << endl;
  }
}
