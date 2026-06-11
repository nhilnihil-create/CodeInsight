#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 303;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, a, b;
	cin >> n >> a >> b;
	if(n>2) {
		a = abs(a-b)-1;
		cout << ((a&1)?"Alice":"Borys");
	} else cout << "Borys";
}

