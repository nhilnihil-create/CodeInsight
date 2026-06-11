#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

int n;

int main(void){
	cin >> n;
	vector<string> w(n);
	unordered_map<string, bool> mp;
	rep(i, n) cin >> w[i];
	mp[w[0]] = true;
	for(int i = 1; i < n; i++){
		if(mp[w[i]] == true){
			cout << "No" << endl;
			return 0;
		}
		if(w[i-1][w[i-1].size()-1] != w[i][0]){
			cout << "No" << endl;
			return 0;
		}
		mp[w[i]] = true;
	}
	cout << "Yes" << endl;
	return 0;
}
