#include<bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c; cin >> a >> b >> c;
	if(c == max({a, b, c}) || c == min({a, b, c})) cout << "No" << endl;
	else cout << "Yes" << endl;
	return 0;
}
