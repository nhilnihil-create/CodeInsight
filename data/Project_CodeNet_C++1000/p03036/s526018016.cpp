#include<iostream>
using namespace std;
int main(void){
  	int A, B, C;
  	cin >> A >> B >> C;
	for ( int i = 0; i < 10; i++ ){
  		cout << A * C - B << endl;
    	C = A * C - B;
    }
	return 0;
}