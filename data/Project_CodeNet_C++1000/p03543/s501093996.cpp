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
	cin >> S;
	if ((S[0] == S[1] && S[1] == S[2]) || (S[1] == S[2] && S[2] == S[3])) cout << "Yes" << endl;
	else cout << "No" << endl;
}
