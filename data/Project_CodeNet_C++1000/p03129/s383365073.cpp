#include <iostream>
using namespace std;

int main() {
	int n,k;cin >> n >>k;
	int cnt = n/2 + n%2;
	if(cnt>=k){
		cout << "YES";
	} else {
		cout << "NO";
	}
	return 0;
}