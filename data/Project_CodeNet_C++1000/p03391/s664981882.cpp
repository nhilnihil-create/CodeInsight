#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
#define vel vector<long long>
#define int long long
#define rep(i,n) for(long long i=0;i<n;i++)
#define sor(v) sort(v.begin(),v.end())
long long p = 998244353;
vel kai(2001, 1);
vel ink(2001, 1);
vel uni(vel &list) {
	if (list.size() == 0) { return list; }
	sort(list.begin(), list.end());
	vel ql(1, list[0]);
	rep(i, list.size() - 1) {
		if (list[i] != list[i + 1]) { ql.push_back(list[i + 1]); }
	}
	return ql;
}
int ru(int a, int r) {
	if (r == 0) { return 1; }
	int ans = ru(a, r / 2);
	ans *= ans; ans %= p;
	if (r % 2 == 1) { ans *= a; }
	return ans % p;
}
int inv(int a) {
	return ru(a, p - 2);
}
void make_kai() {
	rep(i, 2000) { kai[i + 1] = (kai[i] * (i + 1)) % p; }
	rep(i, 2001) { ink[i] = inv(kai[i]); }
}
int com(int n, int r) {
	int ans = kai[n] * ink[r];
	ans %= p; ans *= ink[n - r]; ans %= p;
	return ans;
}
signed main() {
int n; cin >>n ;
bool fl=true;
int mn=1000000000,sum=0;
rep(i,n){
int a,b;cin >> a>>b;
sum+=a;
if(a>b){mn=min(mn,b);fl=false;}
}
if(fl){cout << 0<<endl;}
else{cout << sum-mn<<endl;}
return 0;
}
