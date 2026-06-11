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
	int N;
	priority_queue<int,deque<int>,greater<int>>Q;
	cin>>N;
	for(int i=0;i<N;i++)
	{
		int t;
		cin>>t;
		Q.push(t);
	}
	while(Q.size()>1)
	{
		int t1=Q.top();Q.pop();
		int t2=Q.top();Q.pop();
		if(t2%t1)Q.push(t2%t1);
		Q.push(t1);
	}
	cout<<Q.top()<<endl;
}


