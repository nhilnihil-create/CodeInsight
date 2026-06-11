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
	ll N, H, W;
	ll A, B;
	cin >> N >> H >> W;
	int an = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> A >> B;
		if (A >= H && B >= W) an++;
	}
	cout << an << endl;
}
