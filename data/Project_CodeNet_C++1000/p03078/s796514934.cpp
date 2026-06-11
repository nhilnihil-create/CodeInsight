#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>
#include<math.h>

#define DIV 1000000007
using namespace std;
using ll = long long;

int main(void) {
	int X, Y, Z, K;
	cin >> X >> Y >> Z >> K;

	vector<ll> A(X);
	for (int i = 0; i < X; i++)
		cin >> A[i];
	sort(A.begin(), A.end(), greater<ll>());

	vector<ll> B(Y);
	for (int i = 0; i < Y; i++)
		cin >> B[i];
	sort(B.begin(), B.end(), greater<ll>());

	vector<ll> C(Z);
	for (int i = 0; i < Z; i++)
		cin >> C[i];
	sort(C.begin(), C.end(), greater<ll>());

	vector<vector<vector<bool>>> visit(X + 1, vector<vector<bool>>(Y + 1, vector<bool>(Z+1)));
	pair<ll, vector<int>> cake;
	priority_queue<pair<ll, vector<int>>> pq;
	cake.first = A[0] + B[0] + C[0], cake.second.push_back(0), cake.second.push_back(0), cake.second.push_back(0);
	pq.emplace(cake);
	int cnt = 0;
	while (cnt < K) {
		pair<ll, vector<int>> tp = pq.top();
		pq.pop();
		int a = tp.second[0];
		int b = tp.second[1];
		int c = tp.second[2];
		visit[a][b][c] = true;
		//cout << a << " " << b << " " << c << " ";
		cout << tp.first << endl;
		cnt++;

		if (a + 1 < X) {
			if (!visit[a + 1][b][c]) {
				visit[a + 1][b][c] = true;
				pair<ll, vector<int>> nt;
				nt.first = tp.first - A[a] + A[a + 1];
				nt.second.push_back(a + 1);
				nt.second.push_back(b);
				nt.second.push_back(c);
				pq.push(nt);
			}
		}
		if (b + 1 < Y) {
			if (!visit[a][b + 1][c]) {
				visit[a][b+1][c] = true;
				pair<ll, vector<int>> nt;
				nt.first = tp.first - B[b] + B[b + 1];
				nt.second.push_back(a);
				nt.second.push_back(b + 1);
				nt.second.push_back(c);
				pq.push(nt);
			}
		}
		if (c + 1 < Z) {
			if (!visit[a][b][c + 1]) {
				visit[a][b][c + 1] = true;
				pair<ll, vector<int>> nt;
				nt.first = tp.first - C[c] + C[c + 1];
				nt.second.push_back(a);
				nt.second.push_back(b);
				nt.second.push_back(c + 1);
				pq.push(nt);
			}
		}

	}

}
