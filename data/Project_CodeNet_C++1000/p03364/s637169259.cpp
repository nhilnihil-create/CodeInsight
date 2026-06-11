#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const ll MOD = 1e9+7;
string s[600];
bool sym[600][600];
vector<P> v[2];
int main()
{
	int n;
	ll ans=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
		s[i]=s[i]+s[i];
	}
	for(int i=n;i<2*n;i++)
		s[i]=s[i-n];
	fill(sym[0],sym[600],false);
	if(n==1)
	{
		cout<<1<<endl;
		return 0;
	}
	//2*2を探す
	for(int i=0;i<2*n-2;i++)
	{
		for(int j=0;j<2*n-2;j++)
		{
			if(s[i][j+1]==s[i+1][j])
			{
				sym[i][j]=true;
				v[0].push_back(P(i,j));
			}
		}
	}
	for(int a=3;a<n+1;a++)
	{
		v[a&1].clear();
		for(int i=0;i<v[(a+1)&1].size();i++)
		{
			P p=v[(a+1)&1][i];
			if(sym[p.first+1][p.second+1] &&(p.first+a<=2*n && p.second+a<=2*n)&&(s[p.first][p.second+a-1]==s[p.first+a-1][p.second]))
				v[a&1].push_back(p);
			else
				sym[p.first][p.second]=false;
		}
	}
	ans=v[n&1].size();
	cout<<ans<<endl;
	return 0;
}