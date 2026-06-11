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
	int N;
	cin >> N;

	vector<ll> a(N);
	rep(i, N) cin >> a[i];

	vector<ll> b(N);
	rep(i, N) cin >> b[i];

	ll na = 0;
	ll nb = 0;

	rep(i, N - 1)
	{
		ll diff = b[i] - a[i];

		if (diff == 0) continue;

		if (diff > 0)
		{
			//bのほうが大きい

			//aをストックで増やす
			//aは2ずつしか増やせないことに注意
			if (diff <= 2 * na)
			{
				na -= diff / 2;
				diff = (diff % 2 == 0 ? 0 : 1);
			}
			else
			{
				diff -= 2 * na;
				na = 0;
			}

			if (diff == 0) continue;

			//aだけ増やす
			//差が偶数ならちょうど消すことができる
			//奇数の場合はbも増やして調整
			nb += diff / 2;
		}
		else
		{
			//aのほうが大きい
			diff *= -1;

			//bをストックで増やす
			if (diff <= nb)
			{
				nb -= diff;
				diff = 0;
			}
			else
			{
				diff -= nb;
				nb = 0;
			}

			if (diff == 0) continue;

			//bだけ増やす
			//aの増分は後続に押し付け
			na += diff;
		}
	}


	//最後の1項を調整
	//na、nbを使い切る
	ll la = a.back() + 2 * na;
	ll lb = b.back() + nb;

	if (la > lb)
	{
		//aのほうが大きい場合、調整不可能
		cout << "No" << endl;
	}
	else
	{
		cout << "Yes" << endl;
	}

	return 0;
}