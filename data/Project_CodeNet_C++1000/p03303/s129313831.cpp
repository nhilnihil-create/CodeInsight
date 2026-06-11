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
	string S;
	int w;
	cin >> S >> w;
	for (int i = 0; i < S.size(); i += w) {
		cout << S[i];
	}
	cout << endl;
}
