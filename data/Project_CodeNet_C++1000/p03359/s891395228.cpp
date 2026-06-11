#define _CRT_SECURE_NO_WARNINGS
#define lp(i,n) for(int i=0;i<n;i++)
#include<bits/stdc++.h>


using namespace std;
int main() {
	int a, b;
	cin >> a >> b;
	if (a == b)
		cout << a << endl;
	else if (a < b)
		cout << a << endl;
	else
		cout << a - 1 << endl;
}