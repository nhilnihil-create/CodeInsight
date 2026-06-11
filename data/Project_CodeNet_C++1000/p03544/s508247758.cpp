#include <iostream>

using namespace std;

typedef unsigned long long ull;

int main(){
	ull num_1 = 2, num_2 = 1;
	int n;
	cin >> n;
	for(int i = 2; i < n+1; i++){
		ull num = num_1 + num_2;
		num_1 = num_2;
		num_2 = num;
	}
	cout <<  num_2 << endl;
	return 0;
}
