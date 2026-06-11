#include <iostream>
#include <math.h>

using namespace std;

int main (void){
	int A,B,x1,x2,x3,m1,m2;
	cin >> A >> B;
	x1 = A + B;
	x2 = A - B;	
	x3 = A * B;
	m1 = (x1+x2+abs(x1-x2))/2;
	m2 = (x3+m1+abs(x3-m1))/2;
	cout << m2;
}