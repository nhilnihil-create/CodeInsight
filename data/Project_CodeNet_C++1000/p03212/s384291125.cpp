#define _USE_MATH_DEFINES
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<sstream>
#include<utility>
#include<map>
#include<climits>
#include<vector>
#include<queue>
#include<algorithm>
#include<set>
#include<stack>
#include<functional>
#include<cmath>
#include<iostream>
using namespace std;
typedef long long ll;
typedef pair<int,int>P;
typedef pair<int,P>MP;
typedef vector<vector<int>> MX;

const ll MOD=1e9+7;
const int INF=1000000000;
//dp[digit][less flag][include 3][include 5][include 7][inccude other]


int dd(string N)
{
	int dp[11][2][2][2][2][2]={0};
	dp[0][0][0][0][0][0]=1;
	for(int i=0;i<N.size();i++)
	{
		int D=N[i]-'0';

		for(int j=0;j<2;j++)
			for(int i3=0;i3<2;i3++)
				for(int i5=0;i5<2;i5++)
					for(int i7=0;i7<2;i7++)
						for(int o=0;o<2;o++)
						{
							for(int d=0;d<=(j?9:D);d++)
							{
								dp[i+1][j||(d<D)][i3||d==3][i5||d==5][i7||d==7][o||(d!=3&&d!=5&&d!=7)]+=dp[i][j][i3][i5][i7][o];
							}
						}
	}
	return dp[N.size()][0][1][1][1][0]+dp[N.size()][1][1][1][1][0];
}


int main()
{
	int res=0;
	string N,p="";
	cin>>N;
	for(int i=0;i<N.length();i++)
	{
		p+="9";
		if(i==N.length()-1)res+=dd(N);
		else res+=dd(p);
	}

	cout<<res<<endl;
}