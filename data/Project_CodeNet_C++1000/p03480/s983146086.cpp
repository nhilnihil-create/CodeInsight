#include "bits/stdc++.h"

using namespace std;

//using Matrix = vector< vector<int> >;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1 << 30;
int dx[5] = {0, 0, 1, -1, 0}, dy[5] = {1, -1, 0, 0, 0};
const double EPS = 1e-10;
bool cmp(P a, P b) { return a.second < b.second; } //End sort (Interval scheduling problem)

string S;

ll ans;

int main(void){
	cin>>S;
	int n = S.size();

	ans = INF;
	for (int k = 0; k + 1 < n; k++) {
		if (S[k] != S[k + 1]) {
			ll tmp = max(k + 1, n - (k + 1));
			ans = min(ans, tmp);
		}
	}

	if (ans == INF) ans = n;

	cout<< ans <<endl;
	
	return 0;
}