#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;
int main() {
	char s[1000];
	string str;
	int n,kari,count=0,ans=0,a,b,c;
	vector<int> x, y;
	cin >> a>>b>>c;
	if (a + b >= c || a + b == c + 1)cout << b + c << endl;
	else cout << c + b - (c - (a + b + 1)) << endl;
}