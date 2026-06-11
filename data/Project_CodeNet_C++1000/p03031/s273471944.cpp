#include<cstdio>
#include<cstdlib>
#include<string>
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
//#include <boost/multiprecision/cpp_int.hpp>

//namespace mp = boost::multiprecision;
using namespace std;
typedef long long ll;
typedef pair<int,int>P;
//using Bint = mp::cpp_int;

int numofbits(int bits)
{
	int num;
	num = (bits >> 1) & 03333333333;
	num = bits - num - ((num >> 1) & 03333333333);  
	num = ((num + (num >> 3)) & 0707070707) % 077;
	return num;
}

int main()
{
	int N,M;
	vector<int>lp,p;
	cin>>N>>M;
	for(int i=0;i<M;i++)
	{
		int t=0;
		int k;
		cin>>k;
		for(int j=0;j<k;j++)
		{
			int q;
			cin>>q;
			q--;
			t|=(1<<q);
		}
		lp.push_back(t);
	}
	for(int i=0;i<M;i++)
	{
		int t;
		cin>>t;
		p.push_back(t);
	}
	int res=0;
	for(int i=0;i<(1<<N);i++)
	{
		bool ok=true;
		for(int l=0;l<M;l++)
		{
			int x=i&lp[l];
			int cnt=numofbits(x);
			ok&=(cnt%2==p[l]);
		}
		if(ok)res++;
	}
	cout<<res<<endl;
}