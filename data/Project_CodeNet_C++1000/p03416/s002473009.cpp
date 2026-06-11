#include <iostream>

using namespace std;

int main()
{
	int A, B;
	cin >> A >> B;
	int count = 0;

	for (int i = A; i <= B; i++) {
		int s = i % 10; // iの左から5桁目
		int t = i /	10000 % 10; // iの左から1桁目
		int u = i /	10 % 10; // iの左から4桁目
		int v = i /	1000 % 10; // iの左から2桁目
		if(s == t && u == v)
			count++;
	}
	cout << count << '\n';
}