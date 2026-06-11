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
ll m[26];

void solve(string S){
	bool flg = true;
	rep(i, S.length()) {
		m[S[i]-'a']++;
	}
	ll a = -1, b = -1;
	rep(i, S.length()) {
		ll maxi = -1, maxv = -1;
		rep(j, 26) {
			if (a != j && b != j) {
				if (maxv < m[j]) {
					maxi = j;
					maxv = m[j];
				}
			}
		}
		// rep(j, 3) {
		// 	cout << m[j];
		// }
		// cout << (char)(maxi+'a') << endl;
		a = b;
		b = maxi;
		if (maxi == -1 || m[maxi] == 0) {
			flg = false;
			break;
		}
		m[maxi]--;
	}
	if (flg) cout << "YES" << endl; else cout << "NO" << endl;
}

int main(){	
	string S;
	cin >> S;
	solve(S);
	return 0;
}

