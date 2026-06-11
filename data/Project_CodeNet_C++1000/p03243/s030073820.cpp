#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <cmath>
#define rep(i,n) for(int i=0; i<n; i++)
#define loop(i, j, n) for(int i=j; i<n; i++)
using namespace std;
int main()
{
	int n;
	cin >> n;

	if(n >= 100 && n <= 111){
		cout << 111 <<endl;
	}else if(n>=112 && n<=222){
		cout << 222 <<endl;
	}else if(n>=223 && n<=333){
		cout << 333 <<endl;
	}else if(n>=334 && n<=444){
		cout << 444 <<endl;
	}else if(n>=445 && n<=555){
		cout << 555 <<endl;
	}else if(n>=556 && n<=666){
		cout << 666 <<endl;
	}else if(n>=667 && n<=777){
		cout << 777 <<endl;
	}else if(n>=778 && n<=888){
		cout << 888 <<endl;
	}else{
		cout << 999 <<endl;
	}
	return 0;
}
