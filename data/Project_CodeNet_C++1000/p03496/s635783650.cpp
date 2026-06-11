// practice with Dukkha
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 50;

int aa[N], n;

void solvep(int ip) {
	int m = n - 1;
	for (int i = 0; i < n; i++)
		if (aa[i] < 0)
			m++;
	cout << m << '\n';
	for (int i = 0; i < n; i++)
		if (aa[i] < 0)
			cout << ip + 1 << ' ' << i + 1 << '\n';
	for (int i = 1; i < n; i++)
		cout << i << ' ' << i + 1 << '\n';
}

void solveq(int iq) {
	int m = n - 1;
	for (int i = 0; i < n; i++)
		if (aa[i] > 0)
			m++;
	cout << m << '\n';
	for (int i = 0; i < n; i++)
		if (aa[i] > 0)
			cout << iq + 1 << ' ' << i + 1 << '\n';
	for (int i = n - 1; i; i--)
		cout << i + 1 << ' ' << i << '\n';
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> aa[i];
	int ip = -1, iq = -1;
	for (int i = 0; i < n; i++)
		if (aa[i] > 0 && (ip == -1 || aa[ip] < aa[i]))
			ip = i;
		else if (aa[i] < 0 && (iq == -1 || aa[iq] > aa[i]))
			iq = i;
	if (ip != -1 && iq == -1)
		solvep(ip);
	else if (ip == -1 && iq != -1)
		solveq(iq);
	else if (ip != -1 && iq != -1) {
		if (aa[ip] + aa[iq] >= 0)
			solvep(ip);
		else
			solveq(iq);
	} else
		cout << "0\n";
	return 0;
}
