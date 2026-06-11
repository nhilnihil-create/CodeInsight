#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define range(a) (a).begin(),(a).end()
#define print(A,x,n) rep(i,0,n){cout<<(i ? " ":"")<<A[i]x;}cout<<endl;
#define pprint(A,y,m,n) rep(j,0,m){print(A[j],y,n);}
const long mod=1e9+7;
const int size=1e6;
const int inf=1e9;
int main(){
	int N,C;cin>>N>>C;
	int D[C][C];
	rep(i,0,C)rep(j,0,C){
		cin>>D[i][j];
	}
	int c; int cnt[3][C];
    rep(i,0,3)rep(j,0,C) cnt[i][j]=0;
	rep(i,0,N)rep(j,0,N){
		cin>>c; c--;
		cnt[(i+j)%3][c]++;
	}
	int ans=inf;
	rep(i,0,C)rep(j,0,C){
        if(j==i) continue;
        rep(k,0,C){
            if(k==i||k==j) continue;
            int sum=0;
            rep(l,0,C){
                sum+=cnt[0][l]*D[l][i];
                sum+=cnt[1][l]*D[l][j];
                sum+=cnt[2][l]*D[l][k];
            }ans=min(ans,sum);
        }
	}
	cout<<ans<<endl;
}