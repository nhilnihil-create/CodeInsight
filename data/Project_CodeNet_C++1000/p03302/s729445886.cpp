#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
using namespace std;
const int mod = 1000000007;
#define ll long long

int main()
{
	int a, b;
	cin >> a >> b;
	if (a + b == 15) cout << '+' << endl;
	else if(a*b==15) cout << '*' << endl;
	else cout << 'x' << endl;
}