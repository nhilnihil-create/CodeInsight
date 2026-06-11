#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A,B;
  cin >> A >> B;
  int num = 0;
  
  for (int i=A;i<B+1;i++){
      int C = i;
      int count = 0;
      int sum = 0;
      
      vector <int> x;
      while(C>0){
          
          int mod = C % 10;
          x.push_back(mod);
          C /= 10;
          count++;
      }
      for (int j=0;j<count;j++){
          
          sum += x.at(j) * pow(10,count-1-j);
          if(sum == i) {
              num++;
          }
      }
  }
  cout << num << endl;
  }
