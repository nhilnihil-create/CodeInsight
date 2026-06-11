#include<iostream>
#include<vector>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int main(void) {
	
	vector<char> x(6);
	rep(i, 6) cin >> x[i];
	if (x[0] == x[5] && x[1] == x[4] && x[2] == x[3]) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;

}