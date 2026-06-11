#include <iostream>

using namespace std;

int main(){
	int n , t, n1, t1;
	cin >> n >> t;
	
	int cost = 10000;
	
	for(int  i = 0 ; i < n; i++){
		cin >> n1 >> t1;
		if(cost > n1 && t >= t1){
			cost = n1;
		}
	}
	if(cost == 10000){
		cout << "TLE";
	}	
	else{
		cout << cost;
	}
		
	
	
	
	
	
	
	
}