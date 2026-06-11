#include <iostream>
#include <string>
#include<cmath>
using namespace std;

int main(void) {
	int N;
	cin >> N;
	int* Xto = new int[N + 1];
	int* Yto = new int[N + 1];
	int* Time = new int[N + 1];
	Time[0] = 0;
	Xto[0] = 0;
	Yto[0] = 0;
	string ans = "Yes";
	for (int i = 0; i < N; i++) {
		cin >> Time[i + 1]>> Xto[i + 1] >> Yto[i + 1];
	}
	for (int i = 0; i < N; i++) {
		int difftime = Time[i + 1] - Time[i];
		int distance = abs(Xto[i + 1] - Xto[i]) + abs(Yto[i + 1] - Yto[i]);
		int going = difftime - distance;
		if (!(going % 2 == 0 && difftime >= distance)) {
			ans = "No";
			break;
		}
	}
	cout << ans;

	delete[] Xto;
	delete[] Yto;
	delete[] Time;
	return 0;
}
