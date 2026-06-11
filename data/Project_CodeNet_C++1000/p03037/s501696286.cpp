#include<bits/stdc++.h>
#define INF 2000000000
#define MOD 1000000007
#define EPS (1e-10)

using namespace std;

int main(int argc, char *argv[]) {

	int N,M; cin >> N >> M;
	
	int l = 1;
	int r = N;
	for (int i = 0; i < M; i++) {
		int L,R; cin >> L >> R;
		l = max(l,L);
		r = min(r,R);
	}
	cout << max(0,r-l+1) << endl;

	return 0;
}
