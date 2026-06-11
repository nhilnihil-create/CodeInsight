#include <bits/stdc++.h>

#define LL long long
#define COIN const int
#define PII pair<int,int>
#define PSI pair<string,int>
#define PIS pair<int,string>

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define REPD(i,n) for((i)=(n)-1;(i)>=0;(i)--)

#define ALL(c) (c).begin(), (c).end()
#define LEN(s) (s).size()
#define CLEAR(x) memset(x,0,sizeof x);

#define MP make_pair
#define PB push_back
#define X first
#define Y second

#define VI vector<int>
#define VS vector<string>
#define VII vector<PII>
#define VVI vector<VI>

#define PIII 3.1415926
#define PI 3.14
/*****************************************************************************/

using namespace std;

map <string,bool> m;
int k,i,j;
string s; 

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin >>s;
	cin >>k;
	int l=s.size();
	if (l>5) l=5;
	for (i=1;i<=l;i++)
	{
		for (j=0;j+i-1<s.size();j++)
		{
			m[s.substr(j,i)]=true;
		}
	}
	map <string,bool>::iterator it=m.begin();
	for (i=1;i<k;i++) it++;
	cout <<it->first<<endl;
	return 0;
}
/******************************************************************************
******************************************************************************/
