#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

string s;
int n,ans;

int main(){
	cin>>s;
	ans=n=s.length();
	for(int i=0;i<n;i++)
		if(s[i]!=s[i+1])
			ans=min(ans,max(i+1,n-i-1));
	printf("%d",ans);
}