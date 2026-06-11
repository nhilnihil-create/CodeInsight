#include<cstdio>
#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;
string s;
int ans=INT_MAX; 
int main()
{
    cin>>s;
    int len=s.length();
    for(int i=1;i<len;i++){
    	if(s[i]!=s[i-1])ans=min(ans,max(i,len-i)); 
	}
    cout<<min(ans,len)<<'\n';
    return 0;
}