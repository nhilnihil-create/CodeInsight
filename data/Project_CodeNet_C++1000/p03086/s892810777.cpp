#include<iostream>
#include<algorithm>
#include<cstring>
#include<stdio.h>
#include<cstdio>
#include<string.h>
#include<cmath>
using namespace std;
int main() {
	bool flag = false;
	string temp;
	cin >> temp;
	int ans = 0;
	int cnt = 0;
	for (int i = 0; i < temp.size(); i++) {
		if (temp[i] == 'A' || temp[i] == 'C' || temp[i] == 'G' || temp[i] == 'T') {
			if (flag == false) {
				flag = true;
				cnt = 1;
			}
			else {
				cnt++;
			}
			if (i == temp.size() - 1) {
				if (cnt > ans)ans = cnt;
			}
		}
		else {
			if (flag == true) {
				if (cnt > ans)ans = cnt;
				flag = false;
			}
			else continue;
		}
	}
	cout << ans << endl;
	return 0;
}