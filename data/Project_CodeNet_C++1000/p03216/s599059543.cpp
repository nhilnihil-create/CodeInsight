#include<bits/stdc++.h>
#define Int long long
using namespace std;
int main()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	int U;
	cin>>U;
	while(U--) 
	{
		Int ans=0,res=0,add=0;
		int tmp;
		cin>>tmp;
		tmp--;
		queue<Int> q;
		for(int i=0;i<n;i++)
		{
			if(s[i]=='D')
			{
				q.push(add);
			}
			else if(s[i]=='M')
			{
				res+=q.size();
				add++;
			}
			else if(s[i]=='C')
			{
				ans+=res;
			}
			if(i>=tmp)
			{
				int k=i-tmp;
				if(s[k]=='D')
				{
					res-=(add-q.front());
					q.pop();
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}