#include<iostream> 
using namespace std;
 
int main() {
	int A,B;
  	cin >> A >> B;
  	B =  A >= 13? B : (A >= 6? (B/2) : 0 );
  	cout << B;
}