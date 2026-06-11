#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(long long i=0;i<x;i++)
#define repn(i,x) for(long long i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
vector<pair<string,P> >vec;
// vector<vector<int>> data(3, vector<int>(4));

ll solve(long long N, string S, long long K){
	ll t = 0, m = 0, c = 0, res = 0;
	rep(i, N+K-1) {
		if (i-K >= 0) {
			if (S[i-K] == 'M') {
				m--;
				t -= c;
			}
			if (S[i-K] == 'C') {
				c--;
			}
		}
		if (i<N && S[i] == 'M') {
			m++;
		}
		if (i<N && S[i] == 'C') {
			c++;
			t += m;
		}
		if (i-K+1 >= 0) {
			if (S[i-K+1] == 'D') {
				res += t;
			}
		}
	}
	return res;
}

int main(){	
	long long N;
	long long Q;
	string S;
	scanf("%lld",&N);
	cin >> S;
	scanf("%lld",&Q);
	vector<long long> k((Q-1)-0+1);
	for(int i = 0 ; i <= (Q-1)-0 ; i++){
		scanf("%lld",&k[i]);
	}
	for(int i = 0 ; i <= (Q-1)-0 ; i++){
		cout << solve(N, S, k[i]) << endl;
	}
	return 0;
}

