// D - Recording
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

int main(){
	int n,c; cin>>n>>c;
	int S[n], T[n], C[n];
	rep(i, n) cin>>S[i]>>T[i]>>C[i];
	int mx_t = 200002; // max time zone
	vector<int> R(mx_t, 0); // Recorder
	rep(cc, c){ // c candidate, cc:[0,C-1]->cc+1:[1,C]
		vector<int> TZ(mx_t, 0); // time zone
		rep(i, n)
			if(C[i] == cc+1){
				TZ[2*S[i] - 1]++;
				TZ[2*T[i]]--;
			}
		rep(i, mx_t - 1){
			TZ[i+1] += TZ[i];
			if(TZ[i+1] > 0) R[i+1]++;
		}
	}
	int ans = 0;
	rep(i, mx_t) ans = max(ans, R[i]);
	cout<< ans <<endl;
}
