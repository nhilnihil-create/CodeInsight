#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define rrep(i,n) for(int i=((int)(n)-1); i>=0; i--)
#define FOR(i,a,n) for(int i=(a); i<(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
	int N; cin >> N;
	string S; cin >> S;

	int b = -1, w = -1;
	bool black = false;
	vector<P> p;
	rep(i, N) {
		if (S[i]=='#' && b==-1) b = i;
		if (S[i]=='.' && b!=-1 && w==-1) w = i;
		if (S[i]=='#' && w!=-1) {
			p.push_back(P(w-b, i-w));
			b = i; w = -1;
		}
	}
	if (b!=-1 && w!=-1) {
		p.push_back(P(w-b, N-w));
	}
	int M = p.size();
	vector<int> B(M), W(M);
	rep(i, M) {
		if (i==0) B[i] = p[i].first;
		else B[i] = B[i-1] + p[i].first;
	}
	rrep(i, M) {
		if (i==M-1) W[i] = p[i].second;
		else W[i] = W[i+1] + p[i].second;
	}
	if (M==0) {
		cout << 0 << endl;
	} else if (M==1) {
		cout << min(B[0], W[0]) << endl;
	} else {
		int ans = INT_MAX;
		rep(i, M) {
			if (i==0) ans = min(ans, W[i]);
			else ans = min(ans, B[i-1]+W[i]);
		}
		cout << ans << endl;
	}
}