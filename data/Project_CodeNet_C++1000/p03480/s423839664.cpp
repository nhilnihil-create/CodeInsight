#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<stack>
#define LL long long
using namespace std;
string f;
int n;
int ans;
int read()
{
	int _=0,__=1;char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')__=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){_=_*10+ch-'0';ch=getchar();}
	return _*__;
}
int main()
    {
        cin>>f;
        ans=f.size();
        n=f.size();
        for(int i=1;i<f.size();i++){
            if(f[i]!=f[i-1])
                ans=min(ans,max(i,n-i));
        }
        cout<<ans<<endl;
        return 0;
	} 
