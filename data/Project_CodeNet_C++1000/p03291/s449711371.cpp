#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
string s;
int d[100005][4];
int add(int &a,int b){
	return a = (a + b)%mod;
}
signed main(){
	cin >> s;
	d[0][0] = 1;
	for(int i = 0; i < s.size() ; i ++){
		for(int j = 0 ; j < 4 ; j ++)
			if(s[i] != '?') add(d[i + 1][j], d[i][j]);
			else add(d[i + 1][j], d[i][j] * 3);
		if(s[i] == 'A' || s[i] == '?')
			add(d[i + 1][1], d[i][0]);
		if(s[i] == 'B' || s[i] == '?')
			add(d[i + 1][2], d[i][1]);
		if(s[i] == 'C' || s[i] == '?')
			add(d[i + 1][3], d[i][2]);
	}
	
	cout << d[s.size()][3];
}
