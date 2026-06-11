#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s1,s2,t,ans="~",s[51];cin>>s1>>t;
	int a=s1.size(),b=t.size(),c=0;
	int n=a-b;
	s2=s1;
	for(int i=n;i>=0;i--){
		bool flag=1;
		for(int j=0;j<b;j++){
			if(s1[i+j]!=t[j]&&s1[i+j]!='?'){
				flag=0;
				break;
			}
		}
		if(flag){
			for(int j=i;j<=i+b-1;j++)s1[j]=t[j-i];
			for(int j=0;j<a;j++){
				if(s1[j]=='?')s1[j]='a';
			}
			s[c]=s1;
			s1=s2;
			c++;
		}
	}
	for(int i=0;i<c;i++)ans=min(ans,s[i]);
	if(ans!="~")cout<<ans;
	else cout<<"UNRESTORABLE";
	return 0;
}