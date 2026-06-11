#include<iostream>
#include<string>
#include<stdio.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int red = 0, blue = 0;
	rep(i, n) {
		if (s.at(i) == 'R') red++;
		else blue++;
	}
	if (red > blue) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}