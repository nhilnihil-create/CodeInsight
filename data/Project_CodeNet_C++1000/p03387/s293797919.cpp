#include<bits/stdc++.h>
using namespace std;
int main()
{
    int s[3],a[3][3],ans=0;
    for(int i=0;i<3;i++) cin>>s[i];
    sort(s,s+3);
    for(int i=0;i<3;i++)
    {
    	for(int j=i+1;j<3;j++)
    	{
    		a[i][j]=(max(s[i],s[j])-min(s[i],s[j]))%2;
    		a[j][i]=a[i][j];
    	}
    }
    for(int i=0;i<3;i++)
    {
    	bool w=true;
    	for(int j=0;j<3;j++)
    	{
    		if(i==j) continue;
    		if(a[i][j]==0) w=false;
    	}
    	if(w==true)
    	{
    		ans++;
    		for(int j=0;j<3;j++)
	    	{
	    		if(i==j) continue;
	    		s[j]++;
	    	}
    	}
    }
    ans+=(s[2]-s[0])/2;
    ans+=(s[2]-s[1])/2;
    cout<<ans<<endl;
}