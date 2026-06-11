#include<bits/stdc++.h>
#define mx 1000000007
#define db double

using namespace std;

db dp[301][301][301]={0},n;

db solve(int c1,int c2,int c3){
    if(dp[c1][c2][c3]!=0)
        return dp[c1][c2][c3];
    if(c1==0 && c2==0 && c3==0)
        return dp[c1][c2][c3]=0;
    db j=0,k=0,l=0,sum=c1+c2+c3;
    if(c1!=0){
        j=(c1/sum)*solve(c1-1,c2,c3);
    }
    if(c2!=0){
        k=(c2/sum)*solve(c1+1,c2-1,c3);
    }
    if(c3!=0){
        l=(c3/sum)*solve(c1,c2+1,c3-1);
    }
    dp[c1][c2][c3]=(n/(sum)) + j+ k +l;
    return dp[c1][c2][c3];

}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int c1=0,c2=0,c3=0;
	int sz;
	cin>> sz ;
	n=sz;
	int p[sz+1];
	for(int i=1;i<=sz;++i){
        cin>> p[i] ;
        if(p[i]==1)
            ++c1;
        if(p[i]==2)
            ++c2;
        if(p[i]==3)
            ++c3;
    }
    cout << fixed << setprecision(15) << solve(c1,c2,c3) ;
	return 0;
}
