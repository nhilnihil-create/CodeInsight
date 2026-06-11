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

void solve(long long N, long long A, long long B){
	if ((B-1-A)%2 == 1) {
		cout << "Alice" << endl;
	} else {
		cout << "Borys" << endl;
	}
}

int main(){	
	long long A;
	long long N;
	long long B;
	scanf("%lld",&N);
	scanf("%lld",&A);
	scanf("%lld",&B);
	solve(N, A, B);
	return 0;
}

