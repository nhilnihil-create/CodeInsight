#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(int)(n); i++)

using namespace std;
typedef long long LL;
typedef pair<int,int> P;
const int INF=2e9;

int main(){
	int N;
	cin >> N;
	bool F[110][5][2];
	rep(i,N){
		rep(j,5){
			rep(k,2) cin >> F[i][j][k];
		}
	}
	int P[110][15];
	rep(i,N){
		rep(j,11) cin >> P[i][j];
	}
	int ans=-1*INF;
	for(int bit=1; bit<(1<<10); bit++){
		int pro=0;
		rep(i,N){
			int c=0;
			rep(j,10){
				if(!(bit&(1<<j))) continue; 
				int day=j%5, time=j%2;
				if(F[i][day][time]) c++;
			}
			pro+=P[i][c];
		}
		ans=max(ans,pro);
	}
	cout << ans << endl;

	return 0;
}