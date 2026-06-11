#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
using Graph = vector<vector<int> >;
using GraphC = vector<vector<char> >;
const int INF = 100000000;
typedef pair<int, int> P;
const int MAX_N = 1000000;
typedef int64_t ll;

ll A, B, C, K;

int main() {
	cin >> A >> B >> C >> K;
	if (K%2==1)
	{
		cout << B - A << endl;
	}
	else {
		cout << A - B << endl;
	}
}