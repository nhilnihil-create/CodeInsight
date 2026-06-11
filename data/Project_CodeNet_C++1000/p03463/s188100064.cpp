#include <bits/stdc++.h>
using namespace std;
#define vec(type) vector<type>

int main() {
	int n, a, b;
	cin >> n >> a >> b;

	if (n==2) cout << "Borys" << endl;
	else if (a==1 && b==2) cout << "Borys" << endl;
	else if (a==n-1 && b==n) cout << "Borys" << endl;
	else if ((b-a)%2==0) cout << "Alice" << endl;
	else cout << "Borys" << endl;
}