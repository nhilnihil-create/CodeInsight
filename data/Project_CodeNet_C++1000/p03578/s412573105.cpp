#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<climits>
#include<iostream>
#include<sstream>
#include<utility>
#include<map>
#include<vector>
#include<queue>
#include<algorithm>
#include<set>
#include<stack>
#include<functional>
using namespace std;
typedef long long ll;
typedef pair<int,int>P;

int main()
{
	int N,M;
	map<int,int>P;
	cin>>N;
	for(int i=0;i<N;i++)
	{
		int t;
		cin>>t;
		P[t]++;
	}
	cin>>M;
	for(int i=0;i<M;i++)
	{
		int t;
		cin>>t;
		if(P[t]>0)
		{
			P[t]--;
		}
		else
		{
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
}