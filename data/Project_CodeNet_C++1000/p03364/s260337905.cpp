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
	char c[N][N];
	rep(i,0,N)rep(j,0,N) cin>>c[i][j];
	int cnt = 0;
	rep(k,0,N){
		bool flag = true;
		rep(i,0,N)rep(j,0,N){
			if(c[i][j] != c[(j-k+N)%N][(i+k)%N]) flag = false;
		}if(flag) cnt++;
	}cout<<cnt * N<<endl;
}