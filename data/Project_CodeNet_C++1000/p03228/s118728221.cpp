#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int A,B,K;
    cin >> A >> B >> K;
  	int count = 0;

    while(true){
        if (A%2 == 1){
            A = A - 1;
          	B = B + A / 2;
            A = A / 2;
        }
        else{
            B = B + A / 2;
          	A = A / 2;
        }
      	count++;
      	if (count >= K){
        	break;
        }
      
		//cout << A << B << endl;

        if (B%2 == 1){
            B = B - 1;
          	A = A + B / 2;
            B = B / 2;
        }
        else{
            A = A + B / 2;
          	B = B / 2;
        }
      	count++;
      	if (count >= K){
        	break;
        }
      	//cout << A << " " << B <<endl;
    }
  	
  	cout << A << " " << B << endl;
}  