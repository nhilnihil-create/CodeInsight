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
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<bool> vb;
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
	int N;
	cin >> N;

	int total = 0;

	int cntA = 0;
	int cntB = 0;
	int cntAB = 0;

	rep(i, N)
	{
		string s;
		cin >> s;

		rep(j, s.size() - 1)
		{
			if(s[j] == 'A' && s[j + 1] == 'B') total++;
		}

		if (s.front() == 'B' && s.back() == 'A')
		{
			cntAB++;
		}
		else if (s.front() == 'B')
		{
			cntB++;
		}
		else if (s.back() == 'A')
		{
			cntA++;
		}
	}

	total += min(cntA, cntB);
	if (cntAB > 0)
	{
		total += cntAB - 1;
		if(cntA > 0 || cntB > 0) total += 1;
	}
	

	cout << total << endl;

	return 0;
}