#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int N;
	bool result = false;
	cin >> N;
  	
  	for ( int i=0; i<= N/4; i++){
    	for ( int j=0; j<= (N-i*4)/7; j++){
        	if( N-i*4-j*7 == 0){
            	result = true;
            }
        }
    }
  	
	if(result){
   		cout << "Yes" << endl;
    }
	else{
    	cout << "No" << endl;
    }
}