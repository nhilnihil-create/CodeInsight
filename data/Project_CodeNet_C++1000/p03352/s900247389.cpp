#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
using Graph = vector<vector<int> >;
using GraphC = vector<vector<char> >;
const int INF = 1000000000;
typedef pair<int, int> P;
const int MAX_N = 1000000000;
const int MAX_E = 100000000;
const int MAX_V = 10000;
typedef int64_t ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }



int main() {
    int X;
	cin >> X;
	if (X == 1)
	{
		cout << 1 << endl;
		return 0;
	}
	int ans = 0;
	for (int i = 2; i*i <=X ; i++)
	{	
		
		int tmp = i * i;
		while (tmp <= X)
		{
			tmp *= i;
		}
		tmp /= i;
		ans = max(ans, tmp);
		
	}
	cout << ans << endl;
}