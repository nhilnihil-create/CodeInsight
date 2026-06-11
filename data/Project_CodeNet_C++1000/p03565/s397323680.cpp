#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<stdio.h>
#include<locale.h>
#include<set>
#include<stack>
#include<queue>
#include<math.h>
using namespace std;

int main()
{
 string s,t;
 cin>>s; cin>>t;
 int inx=0;
 for(int i=0;i<s.size();i++)
 {
	int flg=1;
	for(int j=0;j<t.size();j++)
	{
		if(i+j>=s.size()){flg=0; break;}
		if(s[i+j]!=t[j]){flg=0;}
	}
	if(flg==1){inx=1; break;}
 }
 if(inx==1){for(int i=0;i<s.size();i++){if(s[i]=='?'){s[i]='a';}} }
 if(inx==0){
 	int st=-1;
	for(int i=0;i<s.size();i++)
	{
		int flg=1;
		for(int j=0;j<t.size();j++)
		{
			if(i+j>=s.size()){flg=0; break;}
			if(s[i+j]!=t[j]&&s[i+j]!='?'){flg=0;}
		}
		if(flg==1){st=i;}
	}
	if(st==-1){s="UNRESTORABLE";}
	else{
		for(int i=0;i<s.size();i++)
		{
			if(s[i]=='?'){s[i]='a';}
		}
		for(int i=st;i<st+t.size();i++)
		{
			s[i]=t[i-st];
		}
	}
 }

 cout<<s;
 
}