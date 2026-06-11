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
	int N; cin >> N;
	vector<string> gr(N);
	for (int i = 0; i < N; i++)
		cin >> gr[i];
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		bool flag = true;
		vector<string> gr2 =gr;
		for (int j = 0; j < N && flag; j++) {
			for (int k = 0; k < N; k++) {
				gr2[j][k] = gr[j][(k + i) % N];
			}
		}
		for (int j = 0; j < N&&flag; j++) {
			for (int k = 0; k < N; k++) {
				//cout << j << " " << (k + i) % N << " " << (k + i) % N << " " << j << endl;
				if (gr2[j][k] != gr2[k][j]) {
					flag = false;
					break;
				}				
			}
		}
		if (flag) cnt += N;// cout << "i=" << i << endl;
	}
	cout << cnt << endl;
}
