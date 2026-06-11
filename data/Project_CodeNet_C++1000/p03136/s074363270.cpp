#include<iostream>
using namespace std;
int main(void){
  	int Sum = 0;
  	int MAXNum = 0;
  	int N, L;
  	cin >> N;
  	for ( int i = 0; i < N; i++){
    	cin >> L;
      	Sum += L;
      	MAXNum = max(MAXNum,L);
    }
  	if ( Sum - MAXNum > MAXNum ) cout << "Yes" << endl;
  	else cout << "No" << endl;
	return 0;
}
