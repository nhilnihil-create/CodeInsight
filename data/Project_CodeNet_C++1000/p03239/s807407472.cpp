#include<bits/stdc++.h>

using namespace std;

#define FOR(i, m, n) for (int i = m; i < n; ++i)
#define FORD(i, m, n) for (int i = m; i >= n; --i)
#define REP(i, n) for (int i = 0; i < n; ++i)
#define REP1(i, n) for (int i = 0; i <= n; ++i)
#define REPR(i, n) for (int i = n; i >= 0; --i)
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

using ll = long long;
using ull = unsigned long long;
using ld = long double;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	int N,T;
	cin>>N>>T;
	vector<int> c(N);
	vector<int> t(N);
	int C=1001;
	REP(i,N){
		cin>>c[i]>>t[i];
		if(t[i]<=T&&c[i]<C)C=c[i];
	}
	if(C==1001)cout << "TLE" << endl;
	else cout << C << endl;

	return 0;
}
