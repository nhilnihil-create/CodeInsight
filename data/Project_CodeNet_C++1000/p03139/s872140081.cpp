#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,A,B;
  cin >> N >> A >> B;
  int max = 0, min = 0;
  if(A > B){
  	max = B;
  }else{
  	max = A;
  }
  
  min = - N + A + B;
  if(min < 0){
  	min = 0;
  }
  cout << max << " " << min << endl;
}