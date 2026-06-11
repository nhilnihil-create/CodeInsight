#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#define llint long long

using namespace std;

llint n;
string s; 
unordered_map<string, llint> mp;

int main(void)
{
	cin >> n;
	cin >> s;
	string t = s.substr(n/2);
	reverse(t.begin(), t.end());
	
	int N = 1<<n;
	for(int i = 0; i < N; i++){
		string r, b;
		for(int j = 0; j < n; j++){
			if(i & (1<<j)) r += t[j];
			else b += t[j];
		}
		r += "#" + b;
		mp[r]++;
	}
	
	llint ans = 0;
	for(int i = 0; i < N; i++){
		string r, b;
		for(int j = 0; j < n; j++){
			if(i & (1<<j)) r += s[j];
			else b += s[j];
		}
		r += "#" + b;
		ans += mp[r];
	}
	cout << ans << endl;
	
	return 0;
}