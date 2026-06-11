#define _USE_MATH_DEFINES
#include<cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <algorithm>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <iterator>
#include<iomanip>

using namespace std;

#define rep(i,a,b) for(int i=(a), i##_len=(b);i<i##_len;i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(c) begin(c),end(c)

#define int ll
#define SZ(x) ((int)(x).size())
#define pb push_back
#define mp make_pair

typedef long long ll;
//typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<double, double> pdd;
typedef vector<vector<int>> mat;
//typedef unsigned int uint;

template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;

const map<int, int> nn = { {1,2},{2,5},{3,5},{4,4},{5,5},{6,6},{7,3,},{8,7},{9,6} };
bool used[10];
int A[10];
string dp[10010];

bool comp(string A, string B)
{
	if (SZ(A) < SZ(B))return true;
	else if (SZ(A) > SZ(B))return false;

	rep(i, 0, SZ(A))
	{
		if (A[i] > B[i])
		{
			return false;
		}
		else if (A[i] < B[i])
		{
			return true;
		}
	}
	return false;
}

signed main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	rep(i, 0, M)
	{
		cin >> A[i];
	}

	sort(A, A + M);

	vector<int> P;
	int nm = 0;
	rrep(i, 0, M)
	{
		if (!used[nn.at(A[i])])
		{
			used[nn.at(A[i])] = true;
			P.push_back(A[i]);
			nm++;
		}
	}

	fill(dp, dp + N + 1, "-1");
	dp[0] = "";

	rep(i, 1, N + 1)
	{
		rep(j, 0, nm)
		{
			if (nn.at(P[j]) <= i && dp[i - nn.at(P[j])] != "-1")
			{
				string ts = to_string(P[j]) + dp[i - nn.at(P[j])];
				if (dp[i] == "-1" || comp(dp[i],ts))
				{
					dp[i] = ts;
				}
			}
		}
	}

	cout << dp[N] << endl;

	return 0;
}