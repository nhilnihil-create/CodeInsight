#include <bits/stdc++.h>
using namespace std;

int main() {
	int a,b;
	cin >> a >> b;
	int d=b-a;
	cout << (1+d)*d/2-b << '\n';
    return 0;
}