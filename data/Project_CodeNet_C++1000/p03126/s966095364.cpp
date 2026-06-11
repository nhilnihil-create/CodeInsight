#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n,m;
	cin >> n >> m;
	map<int,int> mp;
	rep(i,n){
		int k;
		cin >> k;
		rep(i,k){
			int a;
            cin >> a;
			mp[a]++;
		}
	}
	int cnt = 0;
	for(auto p:mp){
		if(p.second == n) cnt++;
	}
	cout << cnt << endl;
}