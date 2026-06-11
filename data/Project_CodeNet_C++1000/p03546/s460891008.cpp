#include<algorithm>
#include<cmath>
#include<cstdio>
#include<functional>
#include<iomanip>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<string>
#include<utility>
#include<vector>

using namespace std;
typedef long long ll;
const ll mod = 1000000007;
#define rep(i,n) for(int i=0;i<n;i++)
#define repl(i,s,e) for(int i=s;i<e;i++)
#define reple(i,s,e) for(int i=s;i<=e;i++)
#define revrep(i,n) for(int i=n-1;i>=0;i--)

#define vll    vector<ll>
#define vvll   vector<vector<ll>>
#define all(x) (x).begin(),(x).end()


int H, W;
vector<vector<ll>> c;
vector<vector<ll>> A;

int main()
{	
	cin >> H >> W;

	c.resize(10, vector<ll>(10));

	rep(i, 10)
	{
		rep(j, 10)
		{
			cin >> c[i][j];
		}
	}

	A.resize(H, vector<ll>(W));

	rep(i, H)
	{
		rep(j, W)
		{
			cin >> A[i][j];
		}
	}

	rep(k, 10)
	{
		rep(i, 10)
		{
			rep(j, 10)
			{
				c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
			}
		}
	}

	ll ans = 0;

	rep(i, H)
	{
		rep(j, W)
		{
			if (A[i][j] == -1) continue;

			ans += c[A[i][j]][1];
		}
	}

	cout << ans << endl;

	return 0;
}