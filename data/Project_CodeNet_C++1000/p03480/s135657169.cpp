#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
char ss[100010];
int ans=10000000;
int main()
{
	cin>>ss;
	int len=strlen(ss);
	for(int i=1;i<=len-1;i++)
	    if(ss[i]==ss[i-1]) continue;
	    else
		    ans=min(ans,max(i,len-i));
    if(ans==10000000) cout<<len;
	else cout<<ans;
}