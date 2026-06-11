#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int coratz(int n) {
	if (n % 2 == 0) return n / 2;
	else return 3 * n + 1;
} 
int main() {
	int s;
	cin >> s;
	set<int> h;
	h.insert(s);
	int a, b = s;
	int cnt = 1;
	while (true)
	{
		a = coratz(b);
		h.insert(a);
		cnt++;
		if (cnt != h.size()) break;
		b = a;
	}
	cout << cnt << endl;
	 
	return 0;
}