#include<iostream> 
using namespace std;

int main() {
  	int A,P,C=0;
  	cin >> A >> P;
  	P += (A*3);
  	while(P>1) {
    	C+=1;
      	P -= 2;
    }
  	cout << C;
	return 0;
}