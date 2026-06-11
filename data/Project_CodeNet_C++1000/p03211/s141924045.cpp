#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

string s;

int main(void){
	cin >> s;
	int ans = INT_MAX;
	for(int i = 0; i < s.size()-2; i++){
		ans = min(ans, abs(stoi(s.substr(i, 3))-753));
	}
	cout << ans << endl;
	return 0;
}
