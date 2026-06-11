#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define print(A,x,n) rep(I,0,n){cout<<(I ? " ":"")<<A[I]x;}cout<<endl;
#define pprint(A,y,m,n) rep(J,0,m){print(A[J],y,n);}
const long mod=1e9+7;
const int size=1e5;
const int inf=1e9;
int main(){
	int N; cin>>N;
	int P[N];
	rep(i,0,N){ cin>>P[i]; P[i]--; }
	int dp[N] = {}; int t = 0;
	rep(i,0,N){
		if(P[i] == 0) dp[0] = 1;
		else dp[P[i]] = dp[P[i]-1] + 1;
        t = max(t, dp[P[i]]);
	}cout<<N - t<<endl;
}