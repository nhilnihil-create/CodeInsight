#include<algorithm>
#include<cmath>
#include<climits>
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


int main()
{
	int N, H;
	cin >> N >> H;

	vector<int> a(N);
	vector<int> b(N);

	rep(i, N) cin >> a[i] >> b[i];

	sort(all(b), greater<int>());
	vector<int> sum_b(N + 1);

	rep(i, N) sum_b[i + 1] = sum_b[i] + b[i];

	auto max_a = *max_element(all(a));

	int ans = H;

	reple(i, 0, N)
	{
		int tmpH = H - sum_b[i];

		if (tmpH <= 0)
		{
			chmin(ans, i);
		}
		else
		{
			int counta = tmpH / max_a;
			if (tmpH % max_a > 0) counta++;
			chmin(ans, counta + i);
		}
	}

	cout << ans << endl;

	return 0;
}