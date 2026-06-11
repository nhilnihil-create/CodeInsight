#include <iostream>
#include <vector>
#include <bitset>
#define ll long long

using namespace std;

const ll bitsz = 4194304;

int main() {
	
	ll n, i, x, sum = 0;
	cin >> n;
	
	bitset<bitsz> bs;
	bs[0] = 1;
	for (i = 1; i <= n; i++) {
		cin >> x;
		sum += x;
		bs |= bs << x;
	}
	
	ll rez = 0;
	for (int i = 0; i <= sum / 2; i++)
		if (bs[i])	rez = sum - i;
	cout << rez << "\n";
}
