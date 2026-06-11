#include <bits/stdc++.h>
using namespace std;

int main (){
  
  int N;
  int K;
  
  cin >> N >> K;
  
  if(N % 2 == 1){
    if(N / 2 + 1 < K){
      cout << "NO" << endl;
    }
    else{
      cout << "YES" << endl;
    }
  }
  else{
    if(N / 2 < K){
      cout << "NO" << endl;
    }
    else{
      cout << "YES" << endl;
    }
}

}