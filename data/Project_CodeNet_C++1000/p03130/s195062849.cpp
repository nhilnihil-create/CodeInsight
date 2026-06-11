#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<tuple>
#include<iomanip>
#include<map>
#include<queue>
#include<set>
#define int long long
using namespace std;
const int INF = 1e10;
const int ZERO = 0;

signed main() {
	vector<int> graph[4];
	for(int i = 0;i < 3;i++) {
		int A,B;
		cin >> A >> B;
		graph[A - 1].push_back(B - 1);
		graph[B - 1].push_back(A - 1);
	}
	int A = graph[0].size() % 2;
	int B = graph[1].size() % 2;
	int C = graph[2].size() % 2;
	int D = graph[3].size() % 2;
	if(A == 0 && B == 0 && C == 0 && D == 0) {
		cout << "YES" << endl;
	}
	else if(A + B + C + D == 2) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}