#include<bits/stdc++.h>
using namespace std;
int d[100009];
int main()
{
	int n,q,l,r,an;
	string s;
	cin>>n>>q>>s;
	n=(int)s.size()-1;
	for(int i=0;i<n;i++)if(s[i]=='A'&&s[i+1]=='C')d[i]++;
	n++;
	for(int i=1;i<n;i++)d[i]+=d[i-1];

	while(q--)
	{
	cin>>l>>r;
	l--;r--;
	an=d[r]-(l==0?0:d[l-1]);
	if(s[r]=='A'&&r<n-1&&s[r+1]=='C')an--;
	cout<<an<<endl;
		
	}

}

