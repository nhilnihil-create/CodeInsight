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

int main()
{	
	string s;
	cin >> s;

	vector<int> v;

	int idx = 0;
	while(idx < s.size())
	{
		if (s[idx] == 'A')
		{
			v.push_back(1);
			idx++;
		}
		else if (s[idx] == 'B')
		{
			if (idx + 1 < s.size() && s[idx + 1] == 'C')
			{
				v.push_back(2);
				idx += 2;
			}
			else
			{
				v.push_back(0);
				idx += 1;
			}
		}
		else if (s[idx] == 'C')
		{
			v.push_back(0);
			idx += 1;
		}
	}

	ll count = 0;
	ll ans = 0;

	rep(i, v.size())
	{
		if (v[i] == 0)
		{
			count = 0;
		}
		else if (v[i] == 1)
		{
			count++;
		}
		else
		{
			ans += count;
		}
	}

	cout << ans << endl;

	return 0;
}