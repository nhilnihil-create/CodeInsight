#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
typedef long long ll;
ll const MOD = 1000000007;

string t ="abcdefghijklmnopqrstuvwxyz";

int main(){
	int N;
	cin >> N;
	string s;
	cin >> s;
	
	map<char,int> mp;
	
	rep(i,N){
		mp[s[i]]++;
	}
	
	ll ans = 1;
	
	rep(i,t.size()){
		ans *= mp[t[i]] +1;
		ans %= MOD;
	}
	
	cout << ans - 1 << endl;
	
    return 0;
}

