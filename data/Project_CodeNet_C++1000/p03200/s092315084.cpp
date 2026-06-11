#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>

#define DIV 1000000007
#define TE 2e5
using namespace std;
using ll = long long;
using ldb = long double;

int main() {
	string s; cin >> s;
	ll len = s.size();
	ll cnt = 0,bl = 0;
	for (int i = 0; i < len; i++) {
		if (s[i] == 'B')bl++;
		if (s[i] == 'W')cnt += bl;
	}
	cout << cnt << endl;
}
