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
	string S; cin >> S;
	for (int i = 0; i < S.size()-8; i++)
	{
		cout << S[i];
	}
	cout << endl;
}