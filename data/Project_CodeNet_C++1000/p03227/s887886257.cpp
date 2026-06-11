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
	if (S.size() == 2) cout << S << endl;
	else {
		for (int i = 2; i >= 0; i--) {
			cout << S[i];
		}
		cout << endl;
	}
}