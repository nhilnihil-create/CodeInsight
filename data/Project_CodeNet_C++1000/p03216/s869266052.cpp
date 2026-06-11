#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main()
{
	LL n,a[1000]={0},q;
	 string s;
	 cin>>n;
	 cin>>s;
	 cin>>q;
	 while(q--)
	 {LL DMnum=0,Dnum=0,Mnum=0,DMCnum=0,k;
	 cin>>k;
	 	  for(LL i=0;i<s.length();i++)
	  {if(i-k>=0&&s[i-k]=='D')
		   {
		   	Dnum--;
		   	DMnum-=Mnum;
		   }
		   if(i-k>=0&&s[i-k]=='M')
		   {
		   	Mnum--;
		   	
		   }
		   
	  	 if(s[i]=='D')Dnum++;
	  	 if(s[i]=='M')
	  	 {
	  	 	Mnum++;
	  	 	DMnum+=Dnum;
		   }
		   if(s[i]=='C')
		   {
		   	DMCnum+=DMnum;
		   }
		   
	  	 
	  }
	  cout<<DMCnum<<"\n";
	 }
}