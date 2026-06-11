#include <bits/stdc++.h>
#define int long long
using namespace std;

typedef pair<int,int> P;

int cnt = 1;
vector<P> vec;

signed main(){
	int n;
	string s;
	cin >> s;
	n = s.length();
	bool flag = true;
	if(s[n - 1] == '1' || s[0] == '0') flag = false;
	for(int i = 0;i <= n - 2;i++){
		if(s[i] != s[n - i - 2]) flag = false;
	}
	if(!flag){
		cout << -1 << endl;
		return 0;
	}
	int pv = 0,prev1 = 0;
	flag = false;
	for(int i = n / 2 - 1;i >= 0;i--){
		if(s[i] == '1'){
			if(!flag){
				for(int j = 0;j < n - (i + 1);j++) vec.push_back(P(0,cnt++));
				flag = true;
			}else{
				for(int j = 0;j < prev1 - i;j++) vec.push_back(P(pv,cnt++));
			}
			prev1 = i;
			pv = cnt - 1;
		}
	}
	for(P p : vec) cout << p.first + 1 << " " << p.second + 1 << endl;
}