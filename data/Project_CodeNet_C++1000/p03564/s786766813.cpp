#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, K, a1, a2, a = 1;
  cin >> N >> K;
  for(int i = 0; i < N; i++){
    a1 = a * 2;
    a2 = a + K;
    if(a1 < a2){
      a = a1;
    }
    else{
      a = a2;
    }
  }
  cout << a << endl;
}
