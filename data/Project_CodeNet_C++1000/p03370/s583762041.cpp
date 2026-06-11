#include<iostream>
#include<vector>
using namespace std;
int main() {
	int n, x, num ;
	cin >> n >> x;
	num = n;
	vector<int> m(n);
	for(int i = 0; i < n; i++) {
		cin >> m.at(i);
		x -= m.at(i);
	}
	int min=m.at(0);
	for (int i = 1; i < n; i++) {
		if (min > m.at(i))min = m.at(i);
	}
	int y = x / min;
	cout <<  y + n;


}