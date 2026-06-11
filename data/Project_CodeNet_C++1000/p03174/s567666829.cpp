#include <iostream>
#include <cstring>
using namespace std;

const int MAXN    = 21;			//maximum number of couples
const int MAXL    = 1<<21+2;	//maximum number of couples
const int BIG_NUM = 1000000007;

int N;					//number of couples
int dp[MAXN][MAXL];	//dp lookup table
int comp[MAXN];		//compatibility

int solve(int currI,int usedJ){
	if(currI==N)
		return (__builtin_popcount(usedJ)==N);//if all are used
	
	if(dp[currI][usedJ]!=-1)
		return dp[currI][usedJ];

	int total = 0;

	for(int j=0;j<N;j++)
		if( !(usedJ&(1<<j)) && comp[currI]&(1<<j) )
			total = (total+solve(currI+1,usedJ|(1<<j)))%BIG_NUM;

	return dp[currI][usedJ] = total;
}

int main(){
	cin>>N;

	memset(dp  ,-1,sizeof(dp));
	memset(comp, 0,sizeof(comp));

	int temp;
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++){
			cin>>temp;
			comp[i]|=temp<<j;
		}

	cout<<solve(0,0)<<endl;
}
