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
int abc(int a,int b) {
	int x = 0;
	for (int i = b; i <= a; i++) {
		for (int j = b; j <= a; j++) {
			if (j % i >= b)x++;
		}

	}
	return x;
}

int main() {
	int a;
	cin >> a;
	cout << a / 3 << endl;
	return 0;
}
