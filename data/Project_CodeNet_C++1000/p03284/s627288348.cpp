#include<iostream>

using namespace std;
int main(){
	int n,m;
	cin >> n >> m;
	if(n%m == 0) cout << 0;
	else {
		cout << 1;
	}
}