#include<bits/stdc++.h>
using namespace std;
int main()
{
	string sp,t;
	cin>>sp>>t;
	int len=t.size()/*匹配[beg..beg+len-1]*/,lens=sp.size();
	string spc=sp,spci="~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	//main  part
	if(sp==t){cout<<sp;return 0;
	}
	for(int i=0;i<=lens-len;i++) 
	{
		bool flag=1;
		for(int j=0;j<len;j++)
		{
			if(sp[i+j]!=t[j]&&sp[i+j]!='?'){
				flag=0;
				break;
			}
			else spc[i+j]=t[j];
		}
		if(flag&&spci>=spc)spci=spc;
		//cout<<spci<<' '<<spc<<' '<<i<<'\n';
		spc=sp;
	}
	if(spci=="~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~")cout<<"UNRESTORABLE";
	else {
		for(int i=0;i<lens;i++)spci[i]=(spci[i]=='?'?'a':spci[i]);
	cout<<spci;}
}