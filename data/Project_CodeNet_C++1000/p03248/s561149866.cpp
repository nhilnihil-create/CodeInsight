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
	string s;
	cin >> s;
	ll n = s.length();
	if (s[0] == '0' || s[n-2] == '0' || s[n-1] == '1') {
		cout << "-1" << endl;
		return 0;
	}
	for (ll i = 0; i < n-2; i++) {
		if (s[i] != s[n-2-i]) {
			cout << "-1" << endl;
			return 0;
		}
	}

	ll now = 1;

	for (ll i = 0; i < n-1; i++) {
		if (s[i] == '1') {
			cout << now << " " << i+2 << endl;
			now = i+2;
		} else {
			cout << now << " " << i+2 << endl;
		}
	}
	return 0;
}

