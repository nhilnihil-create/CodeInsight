#include <bits/stdc++.h>

using namespace std;
using ll =long long;
typedef pair<int,int> P;
#define SORT(a) sort((a).begin(),(a).end())
#define rSORT(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//Write From this Line

int main()
{
	int k;
	cin >> k;
	vector<ll> a(k);
	rep(i, k)cin>>a[i];
	rSORT(a);

	ll m = 2, M = 2;

	rep(i,k){
		if(m % a[i] != 0){
			if((m + (a[i] - (m%a[i]))) > M){
				puts("-1");
				return 0;
			}
		}
		m = (m+a[i]-1)/a[i] * a[i];
		M = floor(M / a[i]) * a[i] + a[i] - 1;
	}
	cout << m << " " << M << endl;
}
