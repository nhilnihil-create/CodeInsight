#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, K, S;
  cin >> N >> K;
  S = 1;
  for(int i = 0;i < N;i++){
   if(S > K){
     S = S + K;
   }
   else{
     S *= 2;
  }
  }
  cout << S << endl;
}