#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

const int INF=1001001001001001001ll;

int N,A,B;
int P[5555];

int uku[5010][5010];

int dp[5555];

signed main(){
	cin>>N>>A>>B;
	rep(i,N)cin>>P[i+1],P[i+1]++;
	N+=2;
	P[0]=1;P[N-1]=N;
	rep(i,N){
		uku[i+1][P[i]]++;
		rep(j,N)uku[i+1][j+1]+=uku[i][j+1]+uku[i+1][j]-uku[i][j];
	}

	fill_n(dp,5555,INF);
	dp[0]=0;
	for(int i=1;i<N;i++){
		for(int j=0;j<i;j++){
			if(P[j]>P[i])continue;
			int tmp=dp[j];

			tmp+=(uku[i][N]-uku[i][P[i]]-uku[j+1][N]+uku[j+1][P[i]])*A;
			tmp+=(uku[i][P[i]]-uku[i][P[j]]-uku[j+1][P[i]]+uku[j+1][P[j]])*min(A,B);
			tmp+=(uku[i][P[j]]-uku[j+1][P[j]])*B;
			chmin(dp[i],tmp);
		}
	}
	cout<<dp[N-1]<<endl;
	return 0;
}