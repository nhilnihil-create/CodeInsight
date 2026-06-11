#include <bits/stdc++.h>
using namespace std;
 
int main() {
  vector<int64_t> data(100);  



  data.at(0) = 2;
  data.at(1) = 1;
  for(int i = 2; i <=86 ; i++) {
  data.at(i) = data.at(i-1) + data.at(i-2);
  }
  
   int num = 0;
  
  cin >> num;
  
  cout << data.at(num) << endl;
  
}