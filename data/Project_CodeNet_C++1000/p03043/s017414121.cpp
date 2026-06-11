#include <iostream>
#include <iomanip>
using namespace std;

inline int spt(int a){
	if (a == 0) return 1;
	a--;
	a |= a >> 1;
	a |= a >> 2;
	a |= a >> 4;
	a |= a >> 8;
	a |= a >> 16;
	a++;
	return a;
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	cout << setprecision(32);

	int n, k, m;
	cin >> n >> k;
	m = spt(k);
	long long num = 0, den = ((long long) n)*((long long) m);
	for (int i = 1; i <= n; i++){
		if (k % i) num += m/spt((k/i) + 1);
		else num += m/spt(k/i);
	}
	cout << ((double) num)/den << '\n';
}