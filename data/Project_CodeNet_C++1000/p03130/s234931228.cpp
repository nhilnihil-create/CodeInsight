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
	int count[5] = { 0 };
	for (int i = 0; i < 3; i++) {
		cin >> a >> b;
		count[a]++;
		count[b]++;
	}
	if (count[1] == 1 && count[2] != 3 && count[3] != 3 && count[4] != 3) cout << "YES" << endl;
	else cout << "NO" << endl;
}
