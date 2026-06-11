#include <bits/stdc++.h>
using namespace std;

int main() {
				    // *constraint*
  int N,A;    	    // 1<=N<=200
  					// 1<=Ai<=10＾9
  				    // Enter an natural number
  cin  >> N;
  int count = 0;
  vector<int> vec(N);
  int i = 0;
  while(i < N){
  	cin >> vec.at(i);
    i++;
  }
  
  
  bool isEven = true;
  while (1) {
    i = 0;
    while(i < N){
      if((vec.at(i) % 2) != 0){
        isEven = false;
        break;
      }
      vec.at(i) /= 2;
      i++;
    }
    if(isEven == false){
      break;
    }
    count++;
  }
  cout << count << endl;
}
