#include <iostream>
using namespace std;
int main(void){
	int  N,A,B;
  
  	cin >> N;
  
  	if(N<=1){
    	cout << "Hello World"<<endl;
    }else if(N==2){
    	cin >> A >> B;
        cout << A+B<<endl;
    }else{
    	return 1;
    }
	return 0;
}
