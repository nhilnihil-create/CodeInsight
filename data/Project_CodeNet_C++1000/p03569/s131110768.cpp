#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<map>
#include<iomanip>
#include<queue>

using ll = long long;

using namespace std;

int main(){
	string s;
	cin >> s;
	
	string t = s;
	reverse(t.begin() , t.end());
	if(s == t){
		cout << 0 << endl;
		return 0;
	}
	
	vector<int> table(26,0);
	for(int i = 0; i < s.size(); i++){
		table[s[i]-'a']++;
	}
	
	int ng_cnt = 0;
	for(int i = 0; i < 26; i++){
		if(i == ('x'-'a'))continue;
		if(table[i] == 1){
			ng_cnt++;
			if(ng_cnt >= 2){
				cout << -1 << endl;
				return 0;
			}
		}
	}
	
	int ans = 0;
	int n = s.size();
	int l = 0;
	int r = n - 1;
	
	while(1){
		if(l >= r){
			cout << ans << endl;
			return 0;
		}
		if(s[l] == s[r]){
			l++;
			r--;
			continue;
		}
		if(s[l] == 'x'){
			ans++;
			l++;
			continue;
		}	
		if(s[r] == 'x'){
			ans++;
			r--;
			continue;
		}	
		if(s[l] != s[r]){
			cout << -1 << endl;
			return 0;
		}
	}
	return 0;
}
 