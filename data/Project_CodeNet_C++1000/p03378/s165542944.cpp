#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <utility>
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
using namespace std;
int main() {
	int N,M, X;
	int zero=0, las=0;
	cin >> N >> M >> X;
	vector<int> a(M);
	vector<int> b(N);
	for (int i = 0; i < M; i++)cin >> a.at(i);
	for (int i = 0; i < M; i++)b.at(a.at(i)) = 1;
	for (int i = X; i < N; i++)las += b.at(i);
	for (int i = 0; i < X; i++)zero += b.at(i);
	cout << min(zero, las) << endl;
	return 0;
}