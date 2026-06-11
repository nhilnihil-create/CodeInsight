#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B,k;
  cin >> A >> B >> k;
  int m = min(A,B);
  int count = 0;
  for(int i = m ; i >=1 ; i--){
  	if(A % i == 0 && B % i == 0){
    	count++;
    }
    if(count == k){
    	cout << i << endl;
      	break;
    }
  }
}