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

int main(){	
	long long N;
	scanf("%lld",&N);
	if (N == 3) {
		cout << "2 5 63\n";
		return 0;
	}
	if (N == 4) {
		cout << "2 5 20 63\n";
		return 0;
	}
	if (N == 5) {
		cout << "2 3 4 6 9\n";
		return 0;
	}
	if (N == 6) {
		cout << "2 3 4 6 9 12\n";
		return 0;
	}
	priority_queue<ll, vector<ll>, greater<ll> > que1, que2;
	repn(i,30000) {
		if (i%2 == 0) que1.push(i);
		if (i%3 == 0 && i%2 != 0) que2.push(i);
	}
	ll a, b;
	repn(i,5000) {
		b = i;
		a = N-b;
		if ((a%3 == 0 || a%3 == 2) && b%2 == 0 && a >= 2 && b >= 3 && a <= 15000) {
			// cout << a << " " << b << endl;
			break;
		}
	}
	ll c = 0;
	rep(i,a) {
		cout << que1.top();
		que1.pop();
		c++;
		if (c == N) {
			cout << endl; 
			return 0;
		} else cout << " ";
	}
	rep(i,b) {
		cout << que2.top();
		que2.pop();
		c++;
		if (c == N) {
			cout << endl; 
			return 0;
		} else cout << " ";
	}

	return 0;
}

