#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define print(A,x,n) rep(I,0,n){cout<<(I ? " ":"")<<A[I]x;}cout<<endl;
#define pprint(A,y,m,n) rep(J,0,m){print(A[J],y,n);}
const long mod=1e9+7;
const int size=2e5+1;
const int inf=1e9;
int main(){
	int N; cin>>N;
	int C[N]; vector<int> id[size];
	rep(i,0,N){
        cin>>C[i];
        if(id[C[i]].size() == 0 || id[C[i]].back() < i) id[C[i]].push_back(i + 1);
    }
	long dp[N+1]; dp[0] = 1;
    long acm[size] = {};
	rep(i,1,N+1){
		dp[i] = dp[i-1];
        if(i > 1 && C[i-2] == C[i-1]) continue;
        (dp[i] += acm[C[i-1]]) %= mod;
        (acm[C[i-1]] += dp[i-1]) %= mod;
    }cout<<dp[N]<<endl;
}