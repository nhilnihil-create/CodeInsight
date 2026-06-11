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

long long lb = 0, ub = 0;
string s;

bool C1(long long c) {
	string ss;
	cout << c << endl;
	cin >> ss;
	if (ss == "Vacant") exit(0);
	if ((s == ss && lb%2 == c%2) || (s != ss && lb%2 != c%2)) {
		// cout << (s == ss && lb%2 == c%2) << " " << (s != ss && lb%2 != c%2) << " aaa" << endl;
		s = ss;
		return true;
	} else {
		return false;
	}
}

int main(){	
	ll N;
	cin >> N;
	cout << lb << endl;
	cin >> s;
	if (s == "Vacant") exit(0);
	ub = N;
	while (ub - lb > 1) {
		long long mid = (lb + ub) / 2;
		if (C1(mid)) lb = mid;
		else ub = mid;
	}
	return 0;
}

