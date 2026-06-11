#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<stdio.h>
#include<utility>//swapでaとbの値を入れ替える
#define rep(i,n) for(int i=0;i<(n);i++)
#define ll long long
#define s(s) sort(s.begin(),s.end())
#define r(s) reverse(s.begin(),s.end())
using namespace std;

int main() {
	int a, b, c,d;
	cin >> a >> b >> c>>d;
	int ans = min(a, b);
	int abc = min(c, d);
	cout << ans + abc << endl;
	return 0;
}