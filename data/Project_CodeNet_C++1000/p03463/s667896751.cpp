#include <iostream>
using namespace std;

void checkDistance(int a , int b){
	if((b - a + 1) % 2 == 0){
		cout << "Borys" << endl;
	}
	else{
		cout << "Alice" << endl; 
	}
}

int main(){
	int n , a , b;
	cin >> n >> a >> b;
	if(n == 2){
		cout << "Borys" << endl;
		exit(0);
	}

	if(b == a + 1){
		cout << "Borys" << endl;
	}
	else{
		checkDistance(a , b);
	}
}