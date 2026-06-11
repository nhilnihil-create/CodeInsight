#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main() {
  int64_t number = 3;
  int64_t prev0 = 2;
  int64_t prev1 = 1;
  int n;
  cin >> n; 
  if (n==1){
    cout << 1 << endl;
  }
  else if (n==2){
    cout << 3 << endl;
  }
  else{
    for (int i =2; i<=n; i++){
      number = prev0 + prev1;
      prev0 = prev1;
      prev1 = number;
    }
    cout << number << endl;
  }
  
}