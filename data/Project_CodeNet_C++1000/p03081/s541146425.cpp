#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, q; cin >> n >> q;
	string s; cin >> s;
	vector<char> t(q), d(q);
	vector<int> e(q);
	for(int i=0;i<q;i++){
		cin >> t[i] >> d[i];
		if(d[i]=='L'){
			e[i] = -1;
		}else{
			e[i] = 1;
		}
	}
	if(n==1){
		for(int i=0;i<q;i++){
			if(s[0]==t[i]){
				cout << 0 << endl;
				return 0;
			}
		}
		cout << 1 << endl;
		return 0;
	}
	int ok = -1;
	int ng = n;
	while(ng-ok>1){
		int c = (ok+ng)/2;
		int now = c;
		for(int i=0;i<q;i++){
			if(s[now]==t[i]){
				now += e[i];
			}
			if(now<0) break;
		}
		if(now<0){
			ok = c;
		}else{
			ng = c;
		}	
	}
	int left = ng;

	ng = -1;
	ok = n;
	while(ok-ng>1){
		int c = (ok+ng)/2;
		int now = c;
		for(int i=0;i<q;i++){
			if(s[now]==t[i]){
				now += e[i];
			}
			if(now>n-1) break;
		}
		if(now>n-1){
			ok = c;
		}else{
			ng = c;
		}	
	}
	int right = ng;
	cout << right-(left-1) << endl;
	return 0;
}