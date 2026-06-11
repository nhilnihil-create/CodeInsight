#include<iostream>
using namespace std;
int main()
{
	int N, K;
	cin >> N >> K;
	int ans;
	ans = N - (K - 1);
	cout << ans;
}