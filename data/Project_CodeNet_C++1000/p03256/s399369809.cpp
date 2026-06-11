#include <bits/stdc++.h>
using namespace std;
#define lo long
const int lmax=1999999999;
const long long lmx=1999999999999999999;
int n,m,a[200003],b,c;
string s;int cudi[209993];
vector<int>v[200003];
int fix[200003][2],fixx[200003];
int main(){std::ios::sync_with_stdio(false);
cin>>n>>m;
cin>>s;
for(int i=0;i<s.size();i++)
{
	a[i]=s[i]-'A';
}
for(int i=0;i<m;i++)
{
	cin>>b>>c;
	b--;
	c--;
	v[b].push_back(c);
	fix[b][a[c]]++;
	v[c].push_back(b);
	fix[c][a[b]]++;
}
c=0;
for(int i=0;i<n;i++)
{
	for(int j=0;j<2;j++)
	{
		if(fix[i][j]==0)
		{
			cudi[i]=1;
			fixx[c++]=i;
			break;
		}
	}
}
for(int I=0;I<c;I++)
{
	int i=fixx[I];
	for(int j=0;j<v[i].size();j++)
	{
		if(cudi[v[i][j]]==1)
			continue;
		fix[v[i][j]][a[i]]--;
		if(fix[v[i][j]][a[i]]==0)
		{
			cudi[v[i][j]]=1;
			fixx[c++]=v[i][j];
		}
	}
}
if(c==n)
{
	cout<<"No"<<endl;
}
else
{
	cout<<"Yes"<<endl;
}

}
/*

                   *         *
                  * *       * *
                 *   *     *   *
                *     *   *     *
               *       * *       *
               *        *        *
                *               *
                 *             *
                  *           *
                   *         *
                    *       *
                     *     *
                      *   *
                       * *
                        *



*/



