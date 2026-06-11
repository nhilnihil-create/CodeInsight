#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
	int a,b,k;
	cin >> a >> b >> k;
	set<int> da,db;
	for(int i=1;i*i<=a;++i){
		if(a%i==0){
			da.insert(-i);
			da.insert(-a/i);
		}
	}
	for(int i=1;i*i<=b;++i){
		if(b%i==0){
			db.insert(-i);
			db.insert(-b/i);
		}
	}
	for(auto &st:db){
		if(da.count(st)){
			--k;
		}
		if(k==0){
			cout << -st << '\n';
			break;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	//cin >> t;
	while(t--){ 
		solve();
	}
	return 0;
}