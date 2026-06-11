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


vector<ll> getDivisorsList(ll n)
{
    vector<ll> ret;

    for (ll i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ret.push_back(i);
            if (i * i != n) ret.push_back(n / i);
        }
    }

    sort(begin(ret), end(ret));
    return ret;
} 

int main()
{
	int N, M;
	cin >> N >> M;

    auto v = getDivisorsList(M);
    auto lower = lower_bound(all(v), N);

    for(auto iter = lower;iter != v.end(); ++iter)
    {
        if (M % *iter == 0)
        {
            cout << M / *iter << endl;
            return 0;
        }
    }

    cout << 1 << endl;

	return 0;
}	