#include<bits/stdc++.h>
using namespace std;
int i,j,bo,ans;
string st;
int main()
{
	getline(cin,st);
	i=0;j=st.size()-1;
	while(i<=j)
	{  
		if(st[i]==st[j]) {i++;j--;continue;}
		if(st[i]=='x') {i++;ans++;continue;}
		if(st[j]=='x') {j--;ans++;continue;}
		bo=1;break;
	}
	if(bo!=1) cout<<ans<<"\n";
	  else cout<<-1<<"\n";
	return 0;
 } 