#include"bits/stdc++.h"
using namespace std;

int main() {
	int N;
	cin >> N;
	int count = 0;
	if (N / 1000 == 2)count += 1;
	if (N % 1000 / 100 == 2)count += 1;
	if (N % 100 / 10 == 2)count += 1;
	if (N % 10 == 2)count += 1;
	cout << count << endl;
	return 0;
}