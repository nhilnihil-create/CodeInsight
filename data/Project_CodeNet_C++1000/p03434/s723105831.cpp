#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  int sA=0,sB=0;
  
  vector<int> A(N);
  for (int i=0; i<N; i++) {
    cin >> A.at(i);
  }
  
  for (int j=0; j<N; j++) {
    int a=0;
    
    for (int i=0; i<N; i++) {
    	if (a < A.at(i)) {
      	a=A.at(i);
   	 	}
  	}
  
  	for (int i=0; i<N; i++) {
    	if (A.at(i) == a) {
      	A.at(i)=0;
      	break;
    	}
  	}
  
  	if (j%2==0) {
    	sA += a;
  	}
  	else {
    	sB += a;
  	}
  }
  
  cout << sA-sB << endl;
}