#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define size(a) int((a).size())
#define present(c, x) (c.find(x) != c.end()) 

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(0);
	vector<int> ret(11);
	int r,d; cin >> r >> d >> ret[0];
	for (int i = 1; i<=10; i++) {
		ret[i] = ret[i-1] * r - d;
		cout << ret[i] << '\n';
	}
	
	
}

