#include<algorithm>
#include<cmath>
#include<cstdio>
#include<functional>
#include<iomanip>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<string>
#include<utility>
#include<vector>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;
#define rep(i,n) for(int i=0;i<n;i++)
#define repl(i,s,e) for(int i=s;i<e;i++)
#define reple(i,s,e) for(int i=s;i<=e;i++)
#define revrep(i,n) for(int i=n-1;i>=0;i--)
#define all(x) (x).begin(),(x).end()

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int N, A, B, C;
vector<int> L;

int dfs(int i, int a, int b, int c)
{
	if (i == N)
	{
		if (a == 0 || b == 0 || c == 0) return 1000000000;

		//延ばすのも縮めるのも同じMP
		//1本だけのときにも+10してしまっているので、-30引く。
		return abs(A - a) + abs(B - b) + abs(C - c) - 30;
	}
	
	auto ans = dfs(i + 1, a, b, c);
	chmin(ans, dfs(i + 1, a + L[i], b, c) + 10);
	chmin(ans, dfs(i + 1, a, b + L[i], c) + 10);
	chmin(ans, dfs(i + 1, a, b, c + L[i]) + 10);

	return ans;
}

int main()
{	
	
	cin >> N >> A >> B >> C; 

	L.resize(N);
	rep(i, N) cin >> L[i];

	cout << dfs(0, 0, 0, 0) << endl;

	return 0;
}