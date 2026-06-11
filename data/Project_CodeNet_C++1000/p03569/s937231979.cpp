#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string s;

bool is_pal(const string& ss)
{
	const int n = ss.length();
	int i=0, j=n-1;
	while(i<j){
		if(ss[i]!=ss[j]) return false;
		i++,j--;
	}
	return true;
}

void solve()
{
	if(is_pal(s)){
		cout<<0<<'\n';
		return;
	}
	string t;
	for(char c : s)if(c!='x')t+=c;
	if(is_pal(t)){
		const int n = t.length();
		int i = 0, j = n-1;
		int a = 0, b = s.length()-1;
		int ans = 0;
		while(i<=j){
			int cnt1 = 0, cnt2 = 0;
			while(s[a]=='x') cnt1++,a++;
			while(s[b]=='x') cnt2++,b--;
			a++, b--;
			ans+=abs(cnt1-cnt2);
			i++,j--;
		}
		cout<<ans<<'\n';
		
	}else{
		cout<<-1<<'\n';
	}
}

int main()
{
	cin >> s;
	solve();
	return 0;
}