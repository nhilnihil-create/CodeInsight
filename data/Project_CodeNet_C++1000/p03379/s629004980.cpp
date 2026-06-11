#include <bits/stdc++.h>

using namespace std;
using ll = long long;

//container util
#define SORT(c) sort((c).begin(),(c).end())
#define all(a) (a).begin(), (a).end()

//repetition
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

//print
#define pv(val) cerr << #val << '=' << (val) << endl

const int INF = 1e9;

int main(void){

	int N; cin >> N;
	vector<int> X(N);
	REP(i,N) cin >> X[i];

	vector<int> Y = X;
	SORT(Y);

	int idx = (N+1)/2-1;
	int mid = Y[idx];
	int ans;
	REP(i,N){
		if(X[i] <= mid) ans = Y[idx+1];
		else ans = mid;
		cout << ans << endl;
	}





	return 0;

}
