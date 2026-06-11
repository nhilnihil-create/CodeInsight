#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int a[10]={2,10,3,9,4,8,6,12},b[10]={6,2,10,3,9,4,8,12},n,i;
	cin >> n;
	if(n==3){
		cout << "2 5 63" << endl;
	} else if(n%2==0){
		for(i=0;i<n;i++){
			cout << a[i%8]+12*(i-i%8)/8;
			if(i==n-1) cout << endl;
			else cout << " ";
		}
	} else {
		for(i=0;i<n;i++){
			cout << b[(i)%8]+12*((i)-(i)%8)/8;
			if(i==n-1) cout << endl;
			else cout << " ";
		}
	}
	return 0;
}