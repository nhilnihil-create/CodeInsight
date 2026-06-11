#include "bits/stdc++.h"
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000
vector<int> enum_div(int n)//nの約数を列挙
{
	vector<int> ret;
	for(int i=1 ; i*i<=n ; ++i)
	{
		if(n%i == 0)
		{
			ret.push_back(i);
			if(i*i!=n)
			{
				ret.push_back(n/i);
			}
		}
	}
	return ret;
}
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    int ans = 1;
    vector<int> v = enum_div(M);
    sort(v.begin(), v.end());
    rep(i, v.size()) {
        if ((ll)N * v[i] <= (ll)M) {
            ans = v[i];
        }
    }
    cout << ans << endl;

    return 0;
}
