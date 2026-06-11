#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
vector<int>G;
int main()
{
    
	 char ss[100005];
     scanf("%s",ss);
     int ll = strlen(ss);
	 int ans=strlen(ss);
     for(int i=1;i<ll;i++)
     {
     	if(ss[i]!=ss[i-1]) ans=min(ans,max(i,ll-i));
     	
	 }
	 cout<<ans;
	return 0;
}