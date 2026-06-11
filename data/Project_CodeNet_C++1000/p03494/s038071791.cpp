#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N ,A, count;
  cin >> N;
  int MIN = 10000000000;
 
  for(int i = 0; i < N; i++){
    cin >> A;
    count = 0;
     while(A % 2 == 0){
       A = A / 2;
       count = count + 1;
     }
   
    if(MIN > count){
      MIN = count;
    }

 }
  
  cout << MIN << endl;
  
}