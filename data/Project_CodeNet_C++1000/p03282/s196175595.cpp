#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(long long i=0;i<int(N);++i)
using ll = long long;
const int INF = 2147483647;
const ll MOD = 1e9+7;
// const ll INF = 1000000000000000000LL;
 
 
 int main() {
	 string s; cin >> s;
	 ll k; cin >> k;
	 char ans;
	bool flag = true;
	rep(i,s.size()){
		if(s[i]!='1')
			flag = false;
		if(i==k-1) break;
	}
	if(flag){
		cout << 1 << endl;
		return 0;
	}

	 for(int i=0;i<s.size();i++){
		 if(s[i]!='1'){
			 ans = s[i];
			 break;
		 }
	 }
	 cout << ans << endl;
	 return 0;
 }
