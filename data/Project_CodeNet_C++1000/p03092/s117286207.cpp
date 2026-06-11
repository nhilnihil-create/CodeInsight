#include"bits/stdc++.h"
using namespace std;
#define LL long long
#define REP(i, n) for(int (i)=0; (i)<(n); (i)++)
#define PB push_back
#define MP make_pair
#define all(x) x.begin(),x.end()
/*
int N,M;
LL c[100005] = {};
int main(){
	cin >> N >> M;
	for(int i=0; i<M; i++){
		int A,B;
		cin >> A >> B;
		A--; B--;
		c[A]++;
		c[B]++;
	}

	LL f = 0;
	for(int i=0; i<N; i++){
		if(c[i] > 0 && c[i]%2 == 0){
			f += c[i]/2-1;
		}
		else{
			cout << "No" << endl;
			return 0;
		}
	}
	if(f < 2){
		cout << "No" << endl;
		return 0;
	}
	
	cout << "Yes" << endl;

	return 0;
}*/

LL N,A,B;
int p[5000];
LL dp[5000][5001];
LL solve(int now, int hidari){
	if(now == N) return 0;
	if(dp[now][hidari] != -1) return dp[now][hidari];
	LL ans = 0;
	if(p[now] < hidari){
		ans = B+solve(now+1,hidari);
	}
	else{
		ans = min(A+solve(now+1, hidari), solve(now+1,max(hidari,p[now])));
	}
	return dp[now][hidari] = ans;
}
int main(){
	cin >> N >> A >> B;
	for(int i=0; i<N; i++){
		cin >> p[i];
		for(int j=0; j<=N; j++) dp[i][j] = -1;
	}
	cout << solve(0, 0) << endl;

	return 0;
}