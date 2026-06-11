#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cstdlib>
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
#include<ios>
#include<iomanip>

using namespace std;
typedef long long ll;
typedef pair<int,int>P;

int main()
{
	int N;
	string S;
	vector<int>sh,dt;
	cin>>N>>S;
	if(S.length()==1)
	{
		cout<<0<<endl;
		return 0;
	}

	for(int i=0;i<S.length();i++)
	{
		if(i==0)
		{
			sh.push_back(S[i]=='#'?1:0);
			dt.push_back(S[i]=='.'?1:0);
		}
		else
		{
			sh.push_back(sh[i-1]+(S[i]=='#'?1:0));
			dt.push_back(dt[i-1]+(S[i]=='.'?1:0));

		}
	}
	//     mid
	//      l
	//      v
	//......######
	int res=min(sh[S.length()-1],dt[S.length()-1]);
	for(int i=0;i<=S.length();i++)
	{
		int shrep=0,dtrep=0;
		if(i==0)
		{
			dtrep=dt[S.length()-1];
		}
		else if(i==S.length())
		{
			shrep=sh[S.length()-1];
		}
		else
		{
			shrep=sh[i-1];
			dtrep=dt[S.length()-1]-dt[i];
		}
		res=min(res,shrep+dtrep);

	}

	cout<<res<<endl;
}