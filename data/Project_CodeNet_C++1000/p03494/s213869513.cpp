#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  int S= 50;
  for(int i = 0; i < N; i++){
    int A;
    cin >> A;
    int T=0;
  	while (true){
    	if( A%2 == 0 ){
          T++;
          A /= 2;
        }
    	else{
          break;
        }
    }
    if( S > T){
      S = T;
    }
  }
  cout << S << endl;
}