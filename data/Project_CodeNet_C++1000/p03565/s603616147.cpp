#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string s, t;

bool ok(const string& a, const string& b)
{
	for(int i=0;i<a.length();++i){
		if(a[i]!=b[i]&&a[i]!='?') return false;
	}
	return true;
}

void solve()
{
	const int n = s.length();
	const int m = t.length();
	string inf = string(n+1,'z');
	string ans = inf;
	for(int i=0;i+m<=n;++i)if(ok(s.substr(i,m), t)){
		string tmp = s;
		for(int j=0;j<i;++j)if(s[j]=='?')tmp[j]='a';
		for(int j=i;j<i+m;++j)tmp[j]=t[j-i];
		for(int j=i+m;j<n;++j)if(s[j]=='?')tmp[j]='a';
		ans = min(ans, tmp);
	}
	if(ans == inf) cout<<"UNRESTORABLE\n";
	else cout<<ans<<'\n';
}

int main()
{
	cin >> s >> t;
	solve();
	return 0;
}