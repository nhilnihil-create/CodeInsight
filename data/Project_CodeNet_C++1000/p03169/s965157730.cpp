#include<bits/stdc++.h>
//using fixed so that output doesnt comes like 1e9 type
#define pr(x)  cout<<fixed<<setprecision(10)<<x<<endl;
using namespace std;

double n;
double dp[301][301][301];

double solve(int x,int y,int z){
   if(x<0 || y<0 || z<0)
   return 0;
   
   if(x==0 && y==0 && z==0)
   return 0;
   
   if(dp[x][y][z]> -0.9)
   return dp[x][y][z];
   
   double exp = n+ x*(solve(x-1,y,z)) + y*(solve(x+1,y-1,z)) + z*(solve(x,y+1,z-1));
   
   return dp[x][y][z]=exp/(x+y+z);	
}

int main(){
	cin>>n;
	int ones=0,two=0,three=0;
	for(int i=1;i<=n;i++){
		int m;
		cin>>m;
		if(m==1)
		ones++;
		else
		if(m==2)
		two++;
		else
		three++;
	}
	
	memset(dp,-1,sizeof(dp));
	pr(solve(ones,two,three));
}