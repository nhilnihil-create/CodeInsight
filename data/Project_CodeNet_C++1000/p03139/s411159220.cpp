#include<iostream>
#include<string>
#include<algorithm>	
#include<cmath>
using namespace std;
int main() {
	int n, a, b; cin >> n >> a >> b;
	cout << min(a, b) << endl;
	cout << max(a + b - n, 0) << endl;
	cin >> n;
}