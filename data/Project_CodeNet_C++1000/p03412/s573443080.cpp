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

ll dig[30];
ll two[31];

void solve(long long N, vector<long long> a, vector<long long> b){
	two[0] = 1;
	repn(i, 30) {
		two[i] = two[i-1]*2; 
	}
	rep(i, 30) {
		vector<ll> amod(N), bmod(N);
		rep(j, N) {
			amod[j] = a[j]%two[i+1];
			bmod[j] = b[j]%two[i+1];
		}
		SORT(amod);
		rep(j, N) {
			// if (i < 5) {
			// 	cout << i << endl;
			// 	cout << POSL(amod,two[i+1]-bmod[j])-POSL(amod,two[i]-bmod[j]) << " " << (POSL(amod,two[i+1]*2-bmod[j])-POSL(amod,two[i+1]+two[i]-bmod[j])) << endl;
			// 	cout << endl;
			// }
			
			dig[i] += (POSL(amod,two[i+1]-bmod[j])-POSL(amod,two[i]-bmod[j]))%2+(POSL(amod,two[i+1]*2-bmod[j])-POSL(amod,two[i+1]+two[i]-bmod[j]))%2;
			dig[i] %= 2;
		}
	}
	ll res = 0;
	rep(i,30) {
		res += dig[i]*two[i];
	}
	cout << res << endl;
}

int main(){	
	long long N;
	scanf("%lld",&N);
	vector<long long> a(N-1+1);
	vector<long long> b(N-1+1);
	for(int i = 0 ; i <= N-1 ; i++){
		scanf("%lld",&a[i]);
	}
	for(int i = 0 ; i <= N-1 ; i++){
		scanf("%lld",&b[i]);
	}
	solve(N, a, b);
	return 0;
}

