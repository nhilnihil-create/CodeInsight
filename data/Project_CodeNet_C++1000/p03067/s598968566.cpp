#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>

#define rep(i,n) for(int i=0;i<n;i++)
#define llint long long int

using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	if (a > b) {
		swap(a, b);
	}
	if (c > a && c < b) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}