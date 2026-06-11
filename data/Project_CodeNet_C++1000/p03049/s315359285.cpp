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
	int N,res=0;
	vector<int>FB,LA,FBLA;
	cin>>N;
	for(int i=0;i<N;i++)
	{
		string s;
		cin>>s;
		if(s[0]=='B'&&s[s.length()-1]=='A')FBLA.push_back(i);
		else if(s[0]=='B')FB.push_back(i);
		else if(s[s.length()-1]=='A')LA.push_back(i);
		for(int i=0;i<s.length()-1;i++)
		{
			if(s[i]=='A'&&s[i+1]=='B')res++;
		}
	}
	//BxxxxA
	int fbs=FB.size();
	int las=LA.size();
	if(FBLA.size()>0)
	{
		res+=FBLA.size()-1;
		if(fbs>0)
		{
			res++;
			fbs--;
		}
		if(las>0)
		{
			res++;
			las--;
		}
	}
	res+=min(fbs,las);
	cout<<res<<endl;
}