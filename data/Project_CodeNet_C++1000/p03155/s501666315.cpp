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
	int N, H, W;
	cin >> N >> H >> W;
	cout << (N - H + 1) * (N - W + 1) << endl;
}
