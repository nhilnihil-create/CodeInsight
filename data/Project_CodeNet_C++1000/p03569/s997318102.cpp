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
	string s;
	cin >> s;

	deque<char> q(all(s));

	int count = 0;

	while (!q.empty())
	{
		if (q.size() == 1) break;

		if (q.front() == q.back())
		{
			q.pop_front();
			q.pop_back();
			continue;
		}

		if (q.front() == 'x')
		{
			count++;
			q.pop_front();
			continue;
		}

		if (q.back() == 'x')
		{
			count++;
			q.pop_back();
			continue;
		}

		count = -1;
		break;
	}

	cout << count << endl;

	return 0;
}