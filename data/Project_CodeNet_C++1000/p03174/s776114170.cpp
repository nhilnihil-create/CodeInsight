//       Author: Mostafa Mounir Shehab
 
#include <bits/stdc++.h>
using namespace std;
 
#define PI  acos(-1)
#define EPS (1e-10)
#define endl "\n"
#define SZ(v) (int)(v.size())
#define IO ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL), cerr.tie(NULL);
typedef long long ll;
typedef long double ld;
 

 
ll MOD=1e9 + 7;
ll OO=1e9 + 10;
const int N=20 + 1,M=1e5 + 5;
int arr[N][N];
int dp[N][(1<<21)];



int n,m,k,cnt,SU,idx,len,MN,MX,T;
int l,r,mid;
int a,b,c;
string str,t;

int Solve(int idx,int mask){
	if(idx == n)
		return 1;
	
	int &ret = dp[idx][mask];
	if(~ret)
		return ret;
	ret = 0;
	
	for(int i=0;i<n;++i){
		if(arr[idx][i] && !(mask&(1<<i))){
			ret+= Solve(idx+1,mask|(1<<i));
			ret%=MOD;
		}
	}
		
	
	return ret;
}


int main(){
	
	IO
	memset(dp,-1,sizeof dp);
	
	cin>>n;
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			cin>>arr[i][j];
	
	cout<<Solve(0,0)<<endl;

	
}
