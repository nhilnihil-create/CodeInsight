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
bool flg[26];

void solve(string S){
	int n = S.length();
	
	if (n < 26) {
		rep(i, n) {
			flg[S[i]-'a'] = true;
		}
		char c = 'A';
		rep(i, 26) {
			if (!flg[i]) {
				c = i+'a';
				break;
			}
		}
		cout << S+c << endl;
	} else if (S == "zyxwvutsrqponmlkjihgfedcba") {
		cout << "-1" << endl;
	} else {
		int i;
		bool se = false;
		for (i = n-2; i >= 0; i--) {
			if (S[i] < S[i+1]) {
				// cout << i << " " << endl;
				se = true;
				break;
			}
		}
		if (se) {
			char last = 'z';
			for (int j = i; j < n; j++) if (S[j] > S[i]) last = min(last, S[j]); 
			rep(j, i) cout << S[j];
			cout << last << endl;
		} else {
			char c = S[0]+1;
			cout << c << endl;
		}
	}
}

int main(){	
	string S;
	cin >> S;
	solve(S);
	return 0;
}

