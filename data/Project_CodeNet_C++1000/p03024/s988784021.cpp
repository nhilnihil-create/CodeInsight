#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<stdio.h>
#include<utility>//swapでaとbの値を入れ替える
#define rep(i,n) for(int i=0;i<(n);i++)
#define ll long long
#define sort(s) sort(s.begin(),s.end())
#define r(s) reverse(s.begin(),s.end())
using namespace std;
int main(){
	string s;
	int ans = 0;
	cin >> s;
	rep(i, s.size()) {
		if (s[i] == 'o')ans++;
	}
	ans += 15 - s.size();
	if (ans >= 8)cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}