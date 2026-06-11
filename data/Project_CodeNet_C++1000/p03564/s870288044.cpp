#include <bits/stdc++.h>
using namespace std;

int main() {
				    // *constraint*
  int N,K;    	    // 1<=N,K<=10
  				    // enter an integer
  
  int min = 1;
  cin  >> N >> K;
  int i = 1;
  while (i <= N) {
    if((min * 2  - min) < K){
      min *= 2;
    }else{
      min += K;
    }
    i++;
  }
  cout << min << endl;
}
