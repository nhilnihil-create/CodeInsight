#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
	int X, Y, Z, K;
	cin >> X >> Y >> Z >> K;
	vector<vector<vector<char>>> Used(X, vector<vector<char>>(Y, vector<char>(Z, 0)));
	vector<long long> A(X), B(Y), C(Z);
	for (int i = 0; i < X; i++) cin >> A[i];
	for (int i = 0; i < Y; i++) cin >> B[i];
	for (int i = 0; i < Z; i++) cin >> C[i];
	sort(A.begin(), A.end(), greater<long long>());
	sort(B.begin(), B.end(), greater<long long>());
	sort(C.begin(), C.end(), greater<long long>());
	priority_queue<pair<long long, vector<int>>> Q;
	Q.push({ A[0] + B[0] + C[0],{0,0,0} });
	for (int i = 0; i < K; i++) {
		auto p = Q.top();
		int a = p.second[0], b = p.second[1], c = p.second[2];
		cout << p.first << endl;
		Q.pop();
		if (a + 1 < X && !Used[a + 1][b][c]) Q.push({ A[a + 1] + B[b] + C[c], {a + 1,b,c} }), Used[a + 1][b][c] = 1;
		if (b + 1 < Y && !Used[a][b + 1][c]) Q.push({ A[a] + B[b + 1] + C[c], {a,b + 1,c} }), Used[a][b + 1][c] = 1;
		if (c + 1 < Z && !Used[a][b][c + 1]) Q.push({ A[a] + B[b] + C[c + 1], {a,b,c + 1} }), Used[a][b][c + 1] = 1;
	}
}
