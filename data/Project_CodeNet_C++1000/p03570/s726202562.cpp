#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
int t, k;
map<int,int> mp;
string s;
int main(){
	cin >> s;
	mp[0] = 0;
	for(char c: s){
		t ^= 1 << (c - 'a');
		auto it = mp.find(t);
		k = it != mp.end() ? it->second : 300000;
		rep(i,26){
			it = mp.find(t^(1<<i));
			if(it != mp.end()) k = min(k,it->second+1);
		}
		mp[t] = k;
	}
	printf("%d\n", t ? mp[t] : 1);
}