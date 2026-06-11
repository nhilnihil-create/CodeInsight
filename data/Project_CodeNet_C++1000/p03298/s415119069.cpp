#include <bits/stdc++.h>
using namespace std;
int main(){
	int n; cin >> n;
	string s; cin >> s;
	map<string, int> ways[20];
	for(int i = 0; i < 1<<n; i++){
		string in0, in1;
		for(int j = 0; j < n; j++){
			if(i&(1<<j)) in1.push_back(s[j]);
			else in0.push_back(s[j]);
		}
		reverse(in1.begin(), in1.end());
		ways[in0.size()][in0 + in1]++;
	}
	long long ans = 0;
	for(int i = 0; i < 1<<n; i++){
		string in0, in1;
		for(int j = 0; j < n; j++){
			if(i&(1<<j)) in1.push_back(s[j + n]);
			else in0.push_back(s[j + n]);
		}
		reverse(in1.begin(), in1.end());
		ans += ways[n - in0.size()][in1 + in0];
	}
	cout << ans << endl;
	return 0;
}
