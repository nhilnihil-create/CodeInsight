#include<iostream>
using namespace std;
using ll = long long;
int N;
ll L[87];

int main() {
	cin >> N;
	
	L[0] = 2, L[1] = 1;

	for (int i = 2; i <= N; i++) {
		L[i] = L[i - 2] + L[i - 1];
	}

	cout << L[N] << endl;
}