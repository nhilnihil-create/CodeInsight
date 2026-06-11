
// Problem : 
// 			C - String Transformation
// 			Editorial
// 		
// Contest : AtCoder - AtCoder Beginner Contest 110
// URL : https://atcoder.jp/contests/abc110/tasks/abc110_c
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s, t;
	cin >> s >> t;
	map<char, char> mp1, mp2;
	for(int i =0 ; i<s.size(); i++){
		if(mp1.count(s[i]) && mp1[s[i]] != t[i]){
			cout << "No";
			return 0;
		}
		if(mp2.count(t[i]) && mp2[t[i]] != s[i]){
			cout << "No";
			return 0;
		}
		mp1[s[i]] = t[i];
		mp2[t[i]] = s[i];
	}
	cout << "Yes";
}