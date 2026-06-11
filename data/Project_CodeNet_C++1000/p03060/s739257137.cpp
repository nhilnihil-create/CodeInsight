#include<iostream>
using namespace std;
int main() {
	
	//B
	int n;
	cin >> n;
	int i;
	int cost = 0, v[20], c[20];
	for (i = 0; i < n; i++) {
		cin >> v[i];
	}
	for (i = 0; i < n; i++) {
		cin >> c[i];
	}
	for (i = 0; i < n; i++) {
		if (v[i] - c[i] > 0) {
			cost = cost + v[i] - c[i];
		}
	}
	cout << cost << endl;
	return 0;

	//A
	/*
	int a, b, t;
	cin >> a >> b >> t;
	int bb = 0;
	int aa = 0;
	while (aa + a <= t) {
		bb = bb + b;
		aa = aa + a;
	}
	cout << bb << endl;
	return 0;
	*/
}