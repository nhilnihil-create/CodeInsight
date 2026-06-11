#include <iostream>
using namespace std;

int main() {
	int n;cin >>n;
	int cnt = 0;
	while(n>0){
		int res = n%10;
		if(res==2) ++cnt;
		n /=10;
	}
	cout << cnt;
	return 0;
}