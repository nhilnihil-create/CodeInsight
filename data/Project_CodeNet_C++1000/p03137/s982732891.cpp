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
const int INF = 1000000000;


int main()
{
	int N,M;
	vector<int>X;
	priority_queue<int>Q;
	cin>>N>>M;
	vector<int>MP(M,INF);
	for(int i=0;i<M;i++)
	{
		int t;
		cin>>t;
		X.push_back(t);
	}
	sort(X.begin(),X.end());
	for(int i=0;i<M-1;i++)
	{
		Q.push(abs(X[i]-X[i+1]));
	}
	for(int i=0;!Q.empty()&&i<(N-1);i++)Q.pop();

	int res=0;
	while(!Q.empty())
	{
		int t=Q.top();Q.pop();
		res+=t;
	}
	cout<<res<<endl;
	

}


