#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
const ull mod = 1e9 + 7;
#define REP(i,n) for(int i=0;i<(int)n;++i)

int main(){
	ll N;
	cin >> N;
	vector<ll> A(N);
	REP(i, N) cin >> A[i];

	vector<ll> S(N+1);
	S[0] = 0;
	REP(i, N) S[i+1] = S[i] + A[i];

	ll res = LLONG_MAX/3;
	for(int i=1;i<N-2;i++){
		//printf("i: %d\n", i);

		int l = 0-1;
		int u = (i-1)+1;
		while(u-l>1){
			int m = (l+u)/2;
			if(S[m+1]-S[0]<=S[i+1]-S[m+1]){
				l = m;
			}else{
				u = m;
			}
		}
		int leftj = u-1;
		if (leftj==-1) leftj=0;
		//printf("leftj: %d\n", leftj);
		if(leftj != i-1){
			ll cand1 = abs((S[leftj+1]-S[0]) - (S[i+1]-S[leftj+1]));
			ll cand2 = abs((S[leftj+2]-S[0]) - (S[i+1]-S[leftj+2]));
			if (cand2<cand1) leftj +=1;
		}

		l = (i+1)-1;
		u = (N-2)+1;
		while(u-l>1){
			int m = (l+u)/2;
			if(S[m+1]-S[i+1]<=S[N]-S[m+1]){
				l = m;
			}else{
				u = m;
			}
		}
		int rightj = u-1;
		if(rightj==i) rightj=i+1;
		//printf("rightj: %d\n", rightj);
		if(rightj != N-2){
			ll cand1 = abs((S[rightj+1]-S[i+1]) - (S[N]-S[rightj+1]));
			ll cand2 = abs((S[rightj+2]-S[i+1]) - (S[N]-S[rightj+2]));
			if (cand2<cand1) rightj +=1;
		}

		ll p = S[leftj+1] - S[0];
		ll q = S[i+1] - S[leftj+1];
		ll r = S[rightj+1] - S[i+1];
		ll s = S[N] - S[rightj+1];
		ll mi = min(min(min(p, q), r), s); 
		ll ma = max(max(max(p, q), r), s);
		res = min(res, abs(mi-ma));
	}
	cout << res << endl;
    return 0;
}