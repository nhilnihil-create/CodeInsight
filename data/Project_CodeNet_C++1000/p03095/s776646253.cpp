#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	string s;
	cin >> n >> s;
	//それぞれの文字の個数をかけて-1する
	map<char,long long> mp;
	for(int i=0;i<n;i++)
	{
		mp[s.at(i)]++;
	}
	const long long c = 1000000007;
	long long sm=1;
	for(auto itr = mp.begin();itr != mp.end();itr++)
	{
		sm *= itr->second + 1;
		sm %= c;
	}
	cout << sm - 1 << endl;
	return 0;
}
