#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n;
	string s;
	cin >> n >> s;
	int ans = 0;
	for(int i = 0;i < n-1;i++){
		map<char,int> mp1;
		map<char,int> mp2;
		for(int j = 0;j <= i;j++){
			mp1[s[j]] = 1;
		}
		for(int j = i+1;j <= n-1;j++){
			mp2[s[j]] = 1;
		}
		int cnt = 0;
		for(auto p:mp1){
			if(mp2.count(p.first)) cnt++;
		}
		ans = max(ans,cnt);
	}
	cout << ans << endl;
}