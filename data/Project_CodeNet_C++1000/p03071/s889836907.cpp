#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int a, b;
	cin >> a >>b;
	if (a < b)swap(a, b);
	if (a - b >= 1)cout << a+a-1 << endl;
	else cout << a+b << endl;
}