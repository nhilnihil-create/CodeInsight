#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>
#include<tuple>

#define DIV 1000000007
#define TE 2e6+5
using namespace std;
using ll = long long;
using ldb = long double;

int main() {
	string s; cin >> s;
	int len = 4;
	int mx = pow(2, len-1);

	for (int i = 0; i < mx; i++) {
		int temp = s[0]-'0';
		for (int j = 0; j < len - 1; j++) {
			if (i & 1 << j) {
				temp += s[j + 1]-'0';
			}
			else temp -= s[j + 1] - '0';
		}

		if (temp == 7) {
			cout << s[0];
			for (int j = 0; j < len - 1; j++) {
				if (i & 1 << j) {
					cout << "+" << s[j + 1];
				}
				else cout << "-" << s[j + 1];
			}
			cout << "=7" << endl;
			break;
		}
		
	}
	
}
