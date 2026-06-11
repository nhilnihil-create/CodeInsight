#include<iostream>

using namespace std;

int main(){
	int n,k;
	cin >> n >> k;
	
	int num = n % 2 ? n/2 + 1:n/2;
	
	if(num < k){
		cout << "NO" << endl;
	}else{
		cout << "YES" << endl;
	}
	return 0;
}