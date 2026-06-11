#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,n) for(int i=(a); i<(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int main() {
	int N; cin >> N;
	vector<string> A(N);
	rep(i, N) cin >> A[i];

	int a = 0, ab = 0, b = 0, ba = 0;
	rep(i, N) {
		if (A[i].front() == 'B') b++;
		rep(j, A[i].size()) {
			if (A[i][j]=='A' && A[i][j+1]=='B') ab++;
		}
		if (A[i].back() == 'A') a++;
		if (A[i].front()=='B' && A[i].back()=='A') ba++;
	}
	int con = min(a, b);
	if (ba>0 && a==ba && b==ba) con--;
	cout << ab + con << endl;
}