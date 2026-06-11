#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
	string s; cin >> s;
	int n = s.size();
	int cur = 0;
	for(auto i : s) cur += i - '0';
	cout << max( (s.front() - '1') + 9 * (n - 1), cur) << endl;
}