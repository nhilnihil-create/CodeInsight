#include <iostream>

using namespace std;

int main(){
	long long x,y;
	cin >> x >> y;
	
	long long num = x, count = 1;
	
	while(num * 2 <= y){
		num *= 2;
		count++;
	}
	
	cout << count << endl;
	return 0;
}
