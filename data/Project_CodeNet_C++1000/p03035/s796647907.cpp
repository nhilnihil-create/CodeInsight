#include <iostream>
using namespace std;

int main() {
int A; cin>> A;//age
int B; cin>> B;//cost
if(A>=13 && A<=100){
	cout<<B;
}
else if(A>=6 && A<=12){
	int C=B/2;
	cout<< C;
}
else if (A>=0 && A<=5){
printf("0\n");
}
	return 0;
}