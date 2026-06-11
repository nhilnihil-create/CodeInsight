#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
using Graph = vector<vector<int> >;
using GraphC = vector<vector<char> >;
const int INF = 1000000000;
typedef pair<int, int> P;
const int MAX_N = 1000000000;
typedef int64_t ll;
template<class T> inline bool chmax(T & a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T & a, T b) { if (a > b) { a = b; return 1; } return 0; }




int main() {
	int a, b, k;
	cin >> a >> b >> k;
	
	for (int i = a; i <= min(b,a+k-1); i++)
	{
		cout << i << endl;
	}
	for (int i = max(b-k+1,a+k); i <= b; i++)
	{
		cout << i << endl;
	}
}