#include <bits/stdc++.h>
using namespace std;

string s;
int n;
int a[30];
int ma;

int main(){
//	cin.tie(0);
//	ios::sync_with_stdio(false);
	cin >> s;
	n = s.size();
	for(int i=0; i<n; ++i)
		++a[s[i]-'a'];
	for(int i=0; i<26; ++i)
		ma = max(ma, a[i]);
	cout << (ma <= (n+2)/3 ? "YES" : "NO") << "\n";
}