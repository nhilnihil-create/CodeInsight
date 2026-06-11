#include<iostream>
#include<vector>
#include<string>
#include<cmath>


using namespace std;



int main() {
	int n;
	double x[11];
	string u[11];
	double total = 0.0;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x[i] >> u[i];
	}

	for (int i = 0; i < n; i++) {
		if (u[i] == "BTC") {
			total += x[i] * 380000.0;
		}
		else
		{
			total += x[i];
		}
	}

	cout << total;
}