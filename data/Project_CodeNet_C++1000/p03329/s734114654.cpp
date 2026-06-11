#include <iostream>
#include <vector>
#include <cstdlib>
#include <math.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF=100000;
int N;

int main(){

cin>>N;

int dp [200000];
for (int j=0;j<200000;++j)dp[j]=INF;
dp[0]=0;
int ku=0;
for (int i=0;i<=100000;i++){

	chmin(dp[i+1],dp[i]+1);
	for (int j=1;j<=6;++j){ku=pow(6,j);chmin(dp[i+ku],dp[i]+1);}
	for (int j=1;j<=5;++j){ku=pow(9,j);chmin(dp[i+ku],dp[i]+1);}

}

cout<<dp[N]<<endl;
}