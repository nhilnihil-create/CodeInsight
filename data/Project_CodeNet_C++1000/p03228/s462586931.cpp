#include <bits/stdc++.h>
using namespace std;

int main() {
	int A, B, N;
	cin >> A >> B >> N;
	
  	int count = 0;
  	for (int i = 0; i < N; i++){
      if(count % 2 == 0){
        if( A % 2 == 1 ) A--;
        B += A/2;
        A -= A/2;
        count ++;
      }
      else{
        if( B % 2 == 1 ) B--;
        A += B/2;
        B -= B/2;
        count ++;
      }
    }
  cout << A << ' ' << B << endl;
}