#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>

#define DIV 998244353
using namespace std;
using ll = long long;
using ldb = long double;

int main() {
	int N; cin >> N;
	vector<int> a;
	for (int i = 11; i <= 55555; i+=5) {
		bool flag = true;
		int temp = i;		
		for (int j = 2; j <= sqrt(temp); j++) {
			if (temp % j == 0) {
				flag = false;
				break;
			}
		}
		if (flag) a.push_back(i);
	}
	for (int i = 0; i < N; i++)
		cout << a[i]<<" ";
	cout << endl;
}