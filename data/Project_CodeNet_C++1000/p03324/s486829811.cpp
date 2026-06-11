#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll d, n;
	cin >> d >> n;
	if(n!=100)cout << (int)pow(100,d)*n << endl;
	else cout << (int)pow(100,d)*101 << endl;
}