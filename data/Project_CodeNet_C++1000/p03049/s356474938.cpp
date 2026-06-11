#include<bits/stdc++.h>
#define ll long long int
using namespace std;
char ch[10006][11];
int min(int a,int b)
{
	if(a>b)return b;
	return a;
}
int main(){
 	int sum=0,a=0,b=0,s=0,n;
 	cin>>n;
 	for(int i=0;i<n;++i)
 	{
 		cin>>ch[i];
 		if(ch[i][0]=='B')b++;
 		if(ch[i][strlen(ch[i])-1]=='A')a++;
 		if(ch[i][0]=='B'&&ch[i][strlen(ch[i])-1]=='A')s++;
 		for(int j=0;j<strlen(ch[i]);++j)
 		{
 			if(ch[i][j]=='A'&&ch[i][j+1]=='B')sum++;
		 }
	 }
	 if(s!=0&&s==b&&s==a)sum+=s-1;
	 else sum+=min(a,b);
	 cout<<sum;
}