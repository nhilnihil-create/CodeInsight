#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for(int i=0; i < n; i++)

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	string s;
	cin>>s;
	vector<int> a(n+1), b(n+1);
	rep(i,n)a[i+1]=s[i]=='#';
	rep(i,n)b[i+1]=s[i]=='.';
	rep(i,n)a[i+1]+=a[i];
	rep(i,n)b[i+1]+=b[i];
	int ans = n;
	rep(i,n+1)ans = min(ans, a[i] + b[n]-b[i]);
	cout<<ans<<endl;
}
