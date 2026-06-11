#include <iostream>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <string>
#define rep(i,beg,end) for(int i=(beg);i<(end);i++)
typedef long long LL;
using namespace std;

int n,num[4];
double dp[301][301][301];
double dfs(int a,int b,int c){
	if(a==0&&b==0&&c==0)return 0;
	//cout<<a<<" "<<b<<" "<<c<<endl;
	if(dp[a][b][c]>0)return dp[a][b][c];
	double ret=1.0*n/(a+b+c);
	if(a>0)ret+=dfs(a-1,b,c)*a/(a+b+c);
	if(b>0)ret+=dfs(a+1,b-1,c)*b/(a+b+c);
	if(c>0)ret+=dfs(a,b+1,c-1)*c/(a+b+c);
	return dp[a][b][c]=ret;
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		int tmp;
		cin>>tmp;
		num[tmp]++;
	}
	cout<<std::fixed<<setprecision(10)<<dfs(num[1],num[2],num[3])<<endl;
	return 0;
}
