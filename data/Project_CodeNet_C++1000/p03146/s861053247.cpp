#include<iostream>
#include<algorithm>
#include<cstring>
#include<stdio.h>
#include<cstdio>
#include<string.h>
#include<cmath>
#include<map>
using namespace std;
map<int, int>room;

int main() {
	int n;
	int cnt=1;
	cin >> n;
	room[n]++;
	while (true) {
		cnt++;
		if (n % 2 == 0) {
			n /= 2;
		}
		else n = 3*n + 1;
		if (room[n]!=0) {
			cout << cnt << endl;
			break;
		}
		else room[n]++;
	}
	return 0;
}