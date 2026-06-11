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

ll solve(long long N, vector<string> S, ll A, ll B){
	bool f = true;
	rep(i, N) {
		rep(j, N) {
			if (S[(A+i)%N][(B+j)%N] != S[(A+j)%N][(B+i)%N]) f = false;
		}
	}
	if (f) return N-A-B; else return 0;
}

int main(){	
	long long N;
	scanf("%lld",&N);
	vector<string> S(N-1+1);
	for(int i = 0 ; i <= N-1 ; i++){
		cin >> S[i];
	}
	ll res = 0;
	rep(i,N) {
		res += solve(N, S, i, 0);
	}
	repn(i,N-1) {
		res += solve(N, S, 0, i);
	}
	cout << res << endl;
	return 0;
}

