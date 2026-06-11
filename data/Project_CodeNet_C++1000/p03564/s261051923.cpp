#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, K;
  cin >> N >> K;
  int tmp = 1;
  
  for(int i; i<N; i++){
    int a, b;
    a = tmp * 2;
    b = tmp + K;
   	if (a<b){
      tmp = a;
    }
    else{
      tmp = b;
    }
  }
  cout << tmp << endl;
}