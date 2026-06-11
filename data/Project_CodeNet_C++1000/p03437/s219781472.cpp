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
	ll X, Y;
	cin >> X >> Y;
	if (X % Y == 0) cout << "-1" << endl;
	else cout << X << endl;
}
